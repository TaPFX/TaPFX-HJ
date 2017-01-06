/* Header file for The TaPMagnetServer thats running
 * on the RaspberryPi with the PWM Expander.
 * Recives Datagramms via UDP from TonMacmini running QLab
 *
 * The Server execute the functions desctipt below
 *
 * If a datagramm not match with this convention
 * the server will ignore the datagramm
 *
 * Server shuts down when it recives "TaPMagnet;EXIT"
 *
 */

#ifndef _TAPMAGNETSERVER_H_
#define _TAPMAGNETSERVER_H_

#include "UDPServer.h"
#include "TaPMagnets.h"
#include <string.h>
#include <stdio.h>
#define DEFAULTPORT 5555

char* MagnetMode;
int MagnetChan;
int DC;
int debug;

signed char parseCommand(char *command);

#endif

/*
 * Commands have to be in this format
 *		TaPFX-HJ;<Function>;<ChannelNumber>[;<DutyCycle>]
 * Valid Values:
 * Function: ON, OFF
 * ChannelNumber: 1-4
 * DutyCycle: 0-100 only when the Function is ON, if not specified DC = 100
 * 
 */
