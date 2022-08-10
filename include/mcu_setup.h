/*
 * mcusetup.h
 * 
 * Vinícius da Silveira Serafim <vinicius@serafim.eti.br>
 */


#ifndef MCUSETUP_H
#define MCUSETUP_H

#ifdef __AVR_ATmega328P__
#include "mcusetup/atmega328p.h"

#elif __AVR_ATmega8__
#include "mcusetup/atmega8.h"

#elif __AVR_ATtiny85__
#include "mcusetup/attiny85.h"

#elif __AVR_ATtiny13A__
#include "mcusetup/attiny13a.h"

#endif

#endif	// MCUSETUP_H

// eof