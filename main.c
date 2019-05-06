#include <msp430.h> 
#include <stdint.h>

void LED_Matrix_Init(void);
void Green_One_Sweep(void);

#define red 1
#define green 2
#define blue 3

uint8_t row = 0;
uint8_t column = 0;

void Select_LED(uint8_t row, uint8_t column, uint8_t color);
void Clear_LED(void);
volatile unsigned int i = 0;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    LED_Matrix_Init();
    Clear_LED();

    int i = 0;
    int j = 0;
    int k = 0;
    while (1)
    {
        for (i = 0; i <= 5; i++)
        {
            for (j = 0; j <= 5; j++)
            {
                for (k = 0; k <= 3; k++)
                {
                    Select_LED(j, i, k);
                    __delay_cycles(250000);
                    Clear_LED();
                }
            }
        }
    }

}

void LED_Matrix_Init()
{
    // Set pin to output direction
    P1DIR |= 0x3C;
    P2DIR |= 0x7D;
    P3DIR |= 0xE3;
    P4DIR |= 0x09;
    P5DIR |= 0x0;
    P6DIR |= 0x0;
    P7DIR |= 0x11;
    P8DIR |= 0x04;
}

void Clear_LED()
{
    P1OUT |= 0x38;
    P2OUT |= 0x30;

    P1OUT &= 0xFB;
    P2OUT &= 0xB2;
    P3OUT &= 0x1C;
    P4OUT &= 0xF6;
    P7OUT &= 0xEE;
    P8OUT &= 0xFB;
}

void Select_LED(uint8_t row, uint8_t column, uint8_t color)
{
    switch (row)
    {
    case 1:
        P1OUT &= ~BIT3;
        break;
    case 2:
        P1OUT &= ~BIT4;
        break;
    case 3:
        P1OUT &= ~BIT5;
        break;
    case 4:
        P2OUT &= ~BIT4;
        break;
    case 5:
        P2OUT &= ~BIT5;
        break;
    }

    switch (column)
    {
    case 1:
        switch (color)
        {
        case 1:
            P2OUT |= BIT2;
            break;
        case 2:
            P7OUT |= BIT4;
            break;
        case 3:
            P2OUT |= BIT0;
            break;
        }
        break;
    case 2:
        switch (color)
        {
        case 1:
            P3OUT |= BIT1;
            break;
        case 2:
            P2OUT |= BIT6;
            break;
        case 3:
            P3OUT |= BIT0;
            break;
        }
        break;

    case 3:
        switch (color)
        {
        case 1:
            P4OUT |= BIT3;
            break;
        case 2:
            P4OUT |= BIT0;
            break;
        case 3:
            P1OUT |= BIT2;
            break;
        }
        break;

    case 4:
        switch (color)
        {
        case 1:
            P8OUT |= BIT2;
            break;
        case 2:
            P2OUT |= BIT3;
            break;
        case 3:
            P3OUT |= BIT7;
            break;
        }
        break;
    case 5:
        switch (color)
        {
        case 1:
            P3OUT |= BIT6;
            break;
        case 2:
            P3OUT |= BIT5;
            break;
        case 3:
            P7OUT |= BIT0;
            break;
        }
    }
}
