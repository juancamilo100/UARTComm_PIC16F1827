
#include "uart.h"

char UART_Init(const long int baudrate)
{
	unsigned int x;
	x = (_XTAL_FREQ - baudrate*64)/(baudrate*64);
	if(x>255)
	{
		x = (_XTAL_FREQ - baudrate*16)/(baudrate*16);
		BRGH = 1;
	}
	if(x<256)
	{
	  SPBRG = x;
	  SYNC = 0; //configures the EUSART for asynchronous operation
	  SPEN = 1; //enables the EUSART and automatically configures the TX/CK I/O pin as an output
      APFCON0bits.RXDTSEL = 0; //RX/DT function is on RB1
      APFCON1bits.TXCKSEL = 0; //TX/CK function is on RB2
      TRISBbits.TRISB1 = 1; //Configures RX/DT (RB1) pin as input
      CREN = 1; //enables the receiver circuitry of the EUSART
      TXEN = 1; //enables the transmitter circuitry
	  return 1;
	}
	return 0;
}

void EnableUARTInterrupt()
{
    PIE1bits.RCIE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

char UART_TX_Empty()
{
  return TRMT;
}

char UART_Data_Ready()
{
   return RCIF;
}
char UART_Read()
{
  return RCREG;
}

void UART_Read_Text(char *Output, unsigned int length)
{
	for(int i=0;i<length;i++)
		Output[i] = UART_Read();
}

void UART_Write(char data)
{
  while(!TRMT); //Wait until the TSR register is empty
  TXREG = data; //Transmission initiated. Transfer data to TSR register.
}

void UART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
	  UART_Write(text[i]);
}