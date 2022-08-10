/*
 * UART (Serial Interface)
 * 
 * Very simple UART implementation.
 * 
 * ATmega328P
 * ATmega8
 */

/*
 * Usage tip:
 *
 * // 1) create a buffer the size you need
 * char buffer[BUFFER_SIZE]; 
 * 
 * // 2) format your data and put it into your buffer
 * snprintf(buffer, BUFFER_SIZE, "printf format\n", var1, var2,...);
 * 
 * // 3) send your buffer out
 * uart_sendString(buffer);
 */

#ifndef UART_H
#define UART_H

//#include "uartbaudrates.h"

#include <math.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>
#include <string.h>

#ifdef BAUD
// This calculates UBRRH_VALUE and UBRRL_VALUE
#include <util/setbaud.h>
#endif

#define BITSET(sfr, bit)        (_SFR_BYTE(sfr) |= _BV(bit))
#define BITCLEAR(sfr, bit)      (_SFR_BYTE(sfr) &= ~_BV(bit))
#define BITINVERT(sfr, bit)     (_SFR_BYTE(sfr) ^= _BV(bit))

void uart_init();
bool uart_dataready();
void uart_rx(bool);
void uart_sendByte(uint8_t);
uint8_t uart_readByte();
void uart_sendString(const char[]);

#endif /* UART_H */

