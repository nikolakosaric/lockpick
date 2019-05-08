#include <msp430.h>
#include <stdint.h>
#include "project_settings.h"
#include "hal_uart.h"
#include "subsystem.h"
#include "task.h"
#include "uart.h"
#include "hal_general.h"
#include "adc.h"
#include "hal_adc.h"

#include "lockpick.h"
#include "LED_matrix.h"

void SetClk24MHz(void);
void SetVcoreUp(unsigned int level);

void printADCValue(uint16_t ADCval, void *);

uint8_t error;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    SetClk24MHz();

    DisableInterrupts();

    Task_Init();

    UART_Init(SUBSYSTEM_UART);
    UART_ReconfigureBaud(SUBSYSTEM_UART, 9600);

    ADC_Init();
    ADC_AddChannel(ADC0, 250, printADCValue, 0);

    LED_Matrix_Init();

    tumbler = 1;
    Tumbler_Values();

    EnableInterrupts();

    error = Lockpick_Arm(100);

    while (1)
    {
        SystemTick();
    }
}

void printADCValue(uint16_t ADCval, void * tempPointer)
{
    uint16_t tumbler_val = Tumbler_Value(tumbler);
    Subsystem_printf("Tumbler: %u\r\n", tumbler);
    Subsystem_printf("ADC Value: %u\r\n", ADCval);
    Subsystem_printf("Tumbler Value: %u\r\n", tumbler_val);
    tumbler = Check_Tumbler_Position(ADCval, tumbler_val, tumbler, error);
    Draw_Tumblers(tumbler);
}

void SetClk24MHz()
{
    // Increase Vcore setting to level3 to support fsystem=25MHz
    // NOTE: Change core voltage one level at a time..
    SetVcoreUp(0x01);
    SetVcoreUp(0x02);
    SetVcoreUp(0x03);

    P5SEL |= BIT2 + BIT3;
    UCSCTL6 &= ~XT2OFF; // Enable XT2
    UCSCTL6 &= ~XT2BYPASS;
    UCSCTL3 = SELREF__XT2CLK; // FLLref = XT2
    UCSCTL4 |= SELA_2 + SELS__DCOCLKDIV + SELM__DCOCLKDIV;

    UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx
    // Loop until XT1,XT2 & DCO stabilizes - In this case only DCO has to stabilize
    do
    {
        UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);
        // Clear XT2,XT1,DCO fault flags
        SFRIFG1 &= ~OFIFG;                      // Clear fault flags
    }
    while (SFRIFG1 & OFIFG);                   // Test oscillator fault flag

    // Disable the FLL control loop
    __bis_SR_register(SCG0);

    // Select DCO range 24MHz operation
    UCSCTL1 = DCORSEL_7;
    /* Set DCO Multiplier for 24MHz
     (N + 1) * FLLRef = Fdco
     (5 + 1) * 4MHz = 24MHz  */
    UCSCTL2 = FLLD0 + FLLN0 + FLLN2;
    // Enable the FLL control loop
    __bic_SR_register(SCG0);

    /* Worst-case settling time for the DCO when the DCO range bits have been
     changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
     UG for optimization.
     32 x 32 x 24MHz / 4MHz = 6144 = MCLK cycles for DCO to settle */
    __delay_cycles(70000);

    // Loop until XT1,XT2 & DCO stabilizes - In this case only DCO has to stabilize
    do
    {
        // Clear XT2,XT1,DCO fault flags
        UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);
        // Clear fault flags
        SFRIFG1 &= ~OFIFG;
    }
    while (SFRIFG1 & OFIFG); // Test oscillator fault flag
}

void SetVcoreUp(unsigned int level)
{
    // Open PMM registers for write
    PMMCTL0_H = PMMPW_H;
    // Set SVS/SVM high side new level
    SVSMHCTL = SVSHE + SVSHRVL0 * level + SVMHE + SVSMHRRL0 * level;
    // Set SVM low side to new level
    SVSMLCTL = SVSLE + SVMLE + SVSMLRRL0 * level;
    // Wait till SVM is settled
    while ((PMMIFG & SVSMLDLYIFG) == 0)
        ;
    // Clear already set flags
    PMMIFG &= ~(SVMLVLRIFG + SVMLIFG);
    // Set VCore to new level
    PMMCTL0_L = PMMCOREV0 * level;
    // Wait till new level reached
    if ((PMMIFG & SVMLIFG))
        while ((PMMIFG & SVMLVLRIFG) == 0)
            ;
    // Set SVS/SVM low side to new level
    SVSMLCTL = SVSLE + SVSLRVL0 * level + SVMLE + SVSMLRRL0 * level;
    // Lock PMM registers for write access
    PMMCTL0_H = 0x00;
}
