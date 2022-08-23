/*
 *  main.cpp
 *
 * Vinícius da Silveira Serafim <vinicius@serafim.eti.br>
 */

#include "main.h"

// To use EEPROM see:
// http://www.nongnu.org/avr-libc/user-manual/group__avr__eeprom.html

/**
 * Main
 */
int main(void)
{
    /* mcu_init must be called first */
    mcu_init();

    /* here goes the setup not covered by mcu_init */

#ifdef BAUD
    usart_init();
    usart_sendString("avr-pio-template\n");
#endif

    /* main loop */
    while (1)
        main_loop();

    // as long as you have an infinite loop above, this will never happen
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    cli();
    sleep_mode();
}

/**
 * Main loop
 */
static inline void main_loop()
{
    LED_ON;
#ifdef BAUD
    usart_sendByte('L');
#endif
    _delay_ms(50);
    LED_OFF;
#ifdef BAUD
    usart_sendByte('.');
#endif
    _delay_ms(950);
}

// eof
