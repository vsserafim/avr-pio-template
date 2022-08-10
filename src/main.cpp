/*
 *  main.cpp
 * 
 * Vinícius da Silveira Serafim <vinicius@serafim.eti.br>
 */

#include "main.h"

// To use EEPROM see:
// http://www.nongnu.org/avr-libc/user-manual/group__avr__eeprom.html

/**
 * Main loop
 */
static inline void main_loop()
{
    LED_ON;
    uart_sendByte('L');
    _delay_ms(50);
    LED_OFF;
    uart_sendByte('.');
    _delay_ms(950);
}

/**
 * Main 
 */
int main(void)
{

    /* must be called first */
    mcu_init();

    /* your setup */
    uart_init();
    uart_sendString("avr-pio-template\n");

    /* main loop */
    while (1)
        main_loop();

    // as long as you have an infinite loop above, this will never happen
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    cli();
    sleep_mode();
}

// eof
