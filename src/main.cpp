/*
 *  main.cpp
 *
 * Vinícius da Silveira Serafim <vinicius@serafim.eti.br>
 * 
 * Tip: do not change the main() function, use setup() and main_loop() instead.
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

    /* setup must be called before the main loop */
    setup();

    /* main loop */
    while (1)
        main_loop();

    // as long as you have an infinite loop above, this will never happen
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    cli();
    sleep_mode();
}

/**
 * Setup
 * Here goes the setup not covered by mcu_init
 */
static inline void setup()
{
#ifdef USART_ENABLED
    usart_init();
    usart_sendString("avr-pio-template\n");
    // rx must be enabled to receive data, default is disabled
    // usart_enable_rx(true);
#endif
}

/**
 * Main loop
 */
static inline void main_loop()
{
    LED_ON;
#ifdef USART_ENABLED
    usart_sendByte('L');
#endif
    _delay_ms(50);
    LED_OFF;
#ifdef USART_ENABLED
    usart_sendByte('.');
#endif
    _delay_ms(950);
}

// eof
