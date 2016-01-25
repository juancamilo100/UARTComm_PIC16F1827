

#ifndef UART_H
#define UART_H

#include "Config.h"

char UART_Init(const long int baudrate);
void EnableUARTInterrupt();
char UART_TX_Empty();
char UART_Data_Ready();
char UART_Read();
void UART_Read_Text(char *Output, unsigned int length);
void UART_Write(char data);
void UART_Write_Text(char *text);

#endif