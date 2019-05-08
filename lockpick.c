/*
 * lockpick.c
 *
 *  Created on: May 6, 2019
 *      Author: nikol
 */

#include "lockpick.h"
uint16_t pos = 0;

uint16_t Tumbler1 = 0;
uint16_t Tumbler2 = 0;
uint16_t Tumbler3 = 0;
uint16_t Tumbler4 = 0;
uint16_t Tumbler5 = 0;

uint8_t Lockpick_Arm(uint8_t difficulty) {
    return difficulty;

}

void Tumbler_Values()
{
    Tumbler1 = random_int(1000, 2047);
    Tumbler2 = random_int(500, 2047);
    Tumbler3 = random_int(1100, 2047);
    Tumbler4 = random_int(75, 2047);
    Tumbler5 = random_int(3600, 2047);
}

uint16_t Tumbler_Value(uint8_t tumbler)
{
    switch (tumbler)
    {
    case 1:
        return Tumbler1;
        break;
    case 2:
        return Tumbler2;
        break;
    case 3:
        return Tumbler3;
        break;
    case 4:
        return Tumbler4;
        break;
    case 5:
        return Tumbler5;
        break;
    }
}

void Draw_ADC_Value(uint16_t ADC_draw_value, uint8_t tumbler, uint8_t color)
{
    Clear_LED();
    if (ADC_draw_value < 820)
    {
        pos = 1;
    }
    else if (ADC_draw_value < 1639)
    {
        pos = 2;
    }
    else if (ADC_draw_value < 2458)
    {
        pos = 3;
    }
    else if (ADC_draw_value < 3277)
    {
        pos = 4;
    }
    else if (ADC_draw_value < 4097)
    {
        pos = 5;
    }
    else
    {
        pos = 1;
    }
    Select_LED(pos, column, color);
}

void Draw_Tumbler1()
{
    Draw_ADC_Value(Tumbler1, 1, blue);
}
void Draw_Tumbler2()
{
    Draw_ADC_Value(Tumbler2, 2, blue);
}
void Draw_Tumbler3()
{
    Draw_ADC_Value(Tumbler3, 3, blue);
}
void Draw_Tumbler4()
{
    Draw_ADC_Value(Tumbler4, 4, blue);
}
void Draw_Tumbler5()
{
    Draw_ADC_Value(Tumbler5, 5, blue);
}

void Draw_Tumblers(uint8_t tumbler)
{

    task_t DrawTum1 = &Draw_Tumbler1;
    task_t DrawTum2 = &Draw_Tumbler2;
    task_t DrawTum3 = &Draw_Tumbler3;
    task_t DrawTum4 = &Draw_Tumbler4;
    task_t DrawTum5 = &Draw_Tumbler5;
    int8_t status1;
    int8_t status2;
    int8_t status3;
    int8_t status4;
    int8_t status5;

    switch (tumbler)
    {
    case 1:

        status1 = Task_Schedule(DrawTum1, 0, 100, 500);
        break;
    case 2:
        status2 = Task_Schedule(DrawTum2, 0, 200, 150);
        Task_Remove(DrawTum1, 0);
        break;
    case 3:
        status3 = Task_Schedule(DrawTum3, 0, 300, 150);
        Task_Remove(DrawTum2, 0);
        break;
    case 4:
        status4 = Task_Schedule(DrawTum4, 0, 400, 150);
        Task_Remove(DrawTum3, 0);
        break;
    case 5:
        status5 = Task_Schedule(DrawTum5, 0, 500, 150);
        Task_Remove(DrawTum4, 0);
        break;
    case 6:
        Task_Remove(DrawTum5, 0);
        break;
    }
}

uint8_t Check_Tumbler_Position(uint16_t ADC_value, uint16_t tumbler_value,
                               uint8_t tumbler, uint8_t error)
{
    if (tumbler > 5)
    {
        Picked();
        return tumbler;
    }
    else
    {
        if ((ADC_value >= (tumbler_value - error))
                && (ADC_value <= (tumbler_value + error)))
        {
            Draw_ADC_Value(tumbler_value, tumbler, green);
            return ++tumbler;
        }
        else
        {
            Draw_ADC_Value(ADC_value, tumbler, red);
            return tumbler;
        }
    }
}

void Picked()
{
    Clear_LED();
}
