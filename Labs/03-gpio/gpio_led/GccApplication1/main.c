/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5
#define LED_WHITE   PC0
#define BUTTON      PD0      // AVR pin where green LED is connected
#define BLINK_DELAY 500
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include "gpio.h"           // GPIO library for AVR-GCC

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed. Functions 
 *           from user-defined GPIO library is used.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Green LED at port B
    GPIO_config_output(&DDRB, LED_GREEN);
    GPIO_write_low(&PORTB, LED_GREEN);

    // Configure the second LED at port C
    GPIO_config_output(&DDRC, LED_WHITE);
    GPIO_write_low(&PORTC, LED_WHITE);

    // Configure Push button at port D and enable internal pull-up resistor
    GPIO_config_input_pullup(&DDRD, BUTTON);

    // Infinite loop
    while (1)
    {
        if ((GPIO_read(&DDRD, BUTTON))== 0) {
        // Pause several milliseconds
        _delay_ms(BLINK_DELAY);
        GPIO_toggle(&DDRB, LED_GREEN);
        GPIO_toggle(&DDRC, LED_WHITE);
        // WRITE YOUR CODE HERE
    }
    }
    // Will never reach this
    return 0;
}