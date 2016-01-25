/* 
 * File:   ButtonMonitoring.h
 * Author: JuanDesktop
 *
 * Created on January 24, 2016, 7:27 PM
 */

#ifndef BUTTONMONITORING_H
#define	BUTTONMONITORING_H
#include "uart.h"

#ifdef	__cplusplus
extern "C" {
#endif

void MonitorMotor1IncrementButton(void);
void MonitorMotor1DecrementButton(void);
void MonitorMotor2IncrementButton(void);
void MonitorMotor2DecrementButton(void);
void MonitorCenteringButton(void);
void MonitorMotor1Buttons(void);
void MonitorMotor2Buttons(void);
void MonitorRelayButton(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONMONITORING_H */

