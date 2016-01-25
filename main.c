/* 
 * File:   main.c
 * Author: JuanDesktop
 *
 * Created on January 23, 2016, 3:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Config.h"
#include <pic16f1827.h>
//#include "uart.h"
#include "ButtonMonitoring.h"

void InitializeOutputPins(void)
{
    TRISAbits.TRISA0 = 0 ;   //   configure RB0 as output
    TRISAbits.TRISA1 = 0 ;
    TRISAbits.TRISA2 = 0 ;
    TRISAbits.TRISA3 = 0 ;
    TRISAbits.TRISA4 = 0 ;
    TRISAbits.TRISA5 = 0 ;
}

void IntializeInputPins(void)
{
    ANSELBbits.ANSELB = 0; // Set all PORTB inputs to digita;
    
    TRISBbits.TRISB0 = 1 ;   // configure RB0 as input - Motor1IncrementButton
    TRISBbits.TRISB3 = 1 ;   // configure RB3 as input - Motor1DecrementButton
    TRISBbits.TRISB4 = 1 ;   // configure RB4 as input - Motor2IncrementButton
    TRISBbits.TRISB5 = 1 ;   // configure RB5 as input - Motor2DecrementButton
    TRISBbits.TRISB6 = 1 ;   // configure RB6 as input - MotorCenteringButton
    TRISBbits.TRISB7 = 1 ;   // configure RB7 as input - RelayButton

    OPTION_REGbits.nWPUEN = 0; //Disable Global Pull-ups
    
    //Set individual inputs to Pull-ups
    WPUBbits.WPUB0 = 1; 
    WPUBbits.WPUB3 = 1;
    WPUBbits.WPUB4 = 1;
    WPUBbits.WPUB5 = 1;
    WPUBbits.WPUB6 = 1;
    WPUBbits.WPUB7 = 1;
}

int main(int argc, char** argv) {

    InitializeOutputPins();
    IntializeInputPins();
    UART_Init(9600);
    EnableUARTInterrupt();


  while(1)
  {
      MonitorMotor1Buttons();
      MonitorMotor2Buttons();
  }  
    return (EXIT_SUCCESS);
}

void interrupt Interrupt(){

    if(RCIF)
    {
      char letterReceived;
      letterReceived = UART_Read();
      
      switch(letterReceived)
      {
          case 'A':
            RA0 = 1;
            __delay_ms(500);
            RA0 = 0;
          break;
          
          case 'B':
            RA1 = 1;
            __delay_ms(500);
            RA1 = 0;
          break;
          
          case 'C':
            RA2 = 1;
            __delay_ms(500);
            RA2 = 0;
          break;
          
          case 'D':
            RA3 = 1;
            __delay_ms(500);
            RA3 = 0;
          break;
          
          case 'E':
            RA4 = 1;
            __delay_ms(500);
            RA4 = 0;
          break;
          
          case 'F':
            RA5 = 1;
            __delay_ms(500);
            RA5 = 0;
          break;
          
          default:
              break;
      }
    }
}

