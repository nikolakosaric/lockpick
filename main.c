#include <msp430.h>
#include <stdint.h>
#include "project_settings.h"
#include "hal_uart.h"
#include "subsystem.h"
#include "task.h"
#include "uart.h"
#include "hal_general.h"

void SetClk24MHz(void);
void SetVcoreUp(unsigned int level);

int A0 = 0;
int A1 = 0;
int A2 = 0;
int A3 = 0;
int A4 = 0;

void Initialize_ADC(void);

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    SetClk24MHz();

    DisableInterrupts();

    //Timing_Init();
    Task_Init();
    UART_Init(SUBSYSTEM_UART);
    UART_ReconfigureBaud(SUBSYSTEM_UART, 9600);
    Initialize_ADC();

    EnableInterrupts();

    while (1)
    {
        SystemTick();
    }
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

void Initialize_ADC()
{
    P6SEL = 0x1F;                             // Enable A/D channel inputs
    ADC12CTL0 = ADC12ON + ADC12MSC + ADC12SHT0_8; // Turn on ADC12, extend sampling time
                                                  // to avoid overflow of results
    ADC12CTL1 = ADC12SHP + ADC12CONSEQ_3; // Use sampling timer, repeated sequence
    ADC12MCTL0 = ADC12INCH_0;                 // ref+=AVcc, channel = A0
    ADC12MCTL1 = ADC12INCH_1;                 // ref+=AVcc, channel = A1
    ADC12MCTL2 = ADC12INCH_2;                 // ref+=AVcc, channel = A2
    ADC12MCTL3 = ADC12INCH_3;                 // ref+=AVcc, channel = A3
    ADC12MCTL4 = ADC12INCH_4 + ADC12EOS;    // ref+=AVcc, channel = A4, end seq.
    ADC12IE = 0x10;                           // Enable ADC12IFG.4
    ADC12CTL0 |= ADC12ENC;                    // Enable conversions
    ADC12CTL0 |= ADC12SC;                     // Start convn - software trigger

}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC12_VECTOR
__interrupt void ADC12ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC12_VECTOR))) ADC12ISR (void)
#else
#error Compiler not supported!
#endif
{
    switch (__even_in_range(ADC12IV, 34))
    {
    case 0:
        break;                           // Vector  0:  No interrupt
    case 2:
        break;                           // Vector  2:  ADC overflow
    case 4:
        break;                           // Vector  4:  ADC timing overflow
    case 6:
        break;                           // Vector  6:  ADC12IFG0
    case 8:
        break;                           // Vector  8:  ADC12IFG1
    case 10:
        break;                           // Vector 10:  ADC12IFG2
    case 12:
        break;                           // Vector 12:  ADC12IFG3
    case 14:                                  // Vector 14:  ADC12IFG4
        A0 = ADC12MEM0;
        A1 = ADC12MEM1;
        A2 = ADC12MEM2;
        A3 = ADC12MEM3;
        A4 = ADC12MEM4;
        break;
    case 16:
        break;                           // Vector 16:  ADC12IFG5
    case 18:
        break;                           // Vector 18:  ADC12IFG6
    case 20:
        break;                           // Vector 20:  ADC12IFG7
    case 22:
        break;                           // Vector 22:  ADC12IFG8
    case 24:
        break;                           // Vector 24:  ADC12IFG9
    case 26:
        break;                           // Vector 26:  ADC12IFG10
    case 28:
        break;                           // Vector 28:  ADC12IFG11
    case 30:
        break;                           // Vector 30:  ADC12IFG12
    case 32:
        break;                           // Vector 32:  ADC12IFG13
    case 34:
        break;                           // Vector 34:  ADC12IFG14
    default:
        break;
    }
}

