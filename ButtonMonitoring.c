
#include <pic16f1827.h>
#include <stdio.h>
#include <stdlib.h>
#include <htc.h>
#include <stdbool.h>
#include "ButtonMonitoring.h"

static bool pressReleaseFlag1 = 0;
static bool pressReleaseFlag2 = 0;
static bool pressReleaseFlag3 = 0;
static bool pressReleaseFlag4 = 0;
static bool pressReleaseFlagCenter = 0;
static bool pressReleaseFlagRelay = 0;

void MonitorMotor1IncrementButton(void)
{
    if((PORTBbits.RB0 == 0) && (pressReleaseFlag1 == 0))
    {
      UART_Write('A');
      __delay_ms(100); 
      pressReleaseFlag1 = 1;
    }
    else if((PORTBbits.RB0 == 1) && (pressReleaseFlag1 == 1))
    {
       pressReleaseFlag1 = 0;
    }  
}

void MonitorMotor1DecrementButton(void)
{
    if((PORTBbits.RB3 == 0) && (pressReleaseFlag2 == 0))
    {
        UART_Write('B');
        __delay_ms(100); 
      pressReleaseFlag2 = 1;
    }
    else if((PORTBbits.RB3 == 1) && (pressReleaseFlag2 == 1))
    {
       pressReleaseFlag2 = 0;
    }  
}

void MonitorMotor2IncrementButton(void)
{
    if((PORTBbits.RB4 == 0) && (pressReleaseFlag3 == 0))
    {
        UART_Write('C');
        __delay_ms(100); 
      pressReleaseFlag3 = 1;
    }
    else if((PORTBbits.RB4 == 1) && (pressReleaseFlag3 == 1))
    {
       pressReleaseFlag3 = 0;
    }  
}

void MonitorMotor2DecrementButton(void)
{
    if((PORTBbits.RB5 == 0) && (pressReleaseFlag4 == 0))
    {
        UART_Write('D');
        __delay_ms(100); 
      pressReleaseFlag4 = 1;
    }
    else if((PORTBbits.RB5 == 1) && (pressReleaseFlag4 == 1))
    {
       pressReleaseFlag4 = 0;
    }  
}

void MonitorCenteringButton(void)
{
    if((PORTBbits.RB6 == 0) && (pressReleaseFlagCenter == 0))
    {
        UART_Write('E');
        __delay_ms(100); 
      pressReleaseFlagCenter = 1;
    }
    else if((PORTBbits.RB6 == 1) && (pressReleaseFlagCenter == 1))
    {
       pressReleaseFlagCenter = 0;
    }  
}

void MonitorMotor1Buttons(void)
{
    MonitorMotor1IncrementButton();
    MonitorMotor1DecrementButton();
}

void MonitorMotor2Buttons(void)
{
    MonitorMotor2IncrementButton();
    MonitorMotor2DecrementButton();
}

void MonitorRelayButton(void)
{
    if((PORTBbits.RB7 == 0) && (pressReleaseFlagRelay == 0))
    {
        UART_Write('F');
        __delay_ms(100); 
      pressReleaseFlagRelay = 1;
    }
    else if((PORTBbits.RB7 == 1) && (pressReleaseFlagRelay == 1))
    {
       pressReleaseFlagRelay = 0;
    }  
}
