# Lab 7: Filip Nimrichetr

Link to this file in your GitHub repository:

[https://github.com/FilipNim/Digital_electronics_2/tree/master/Labs/07-uart](https://github.com/FilipNim/Digital_electronics_2/tree/master/Labs/07-uart)

### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 |
   | Up     | 0.495&nbsp;V | 101 | 99 |
   | Down   | 1.203&nbsp;V |   246  | 257 |
   | Left   | 1.97&nbsp;V  |  403   | 410 |
   | Select | 3.182&nbsp;V |   640  | 640 |
   | none   | 5&nbsp;V |   1023  | 1023 |

2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;                  // Copy ADC result to 16-bit variable
    itoa(value, lcd_string, 10);  // Convert decimal value to string

    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;                  // Copy ADC result to 16-bit variable
     lcd_gotoxy(8,0);
     lcd_puts("    ");
     
     //Put new value to LCD
     itoa(value, lcd_string, 10);  // Convert decimal value to string
     lcd_gotoxy(8,0);
     lcd_puts(lcd_string);
     
     //Send the same value to UART
     uart_puts(lcd_string);
     uart_puts("\n\r");
     
     //Clear previous value
     lcd_gotoxy(13,0);
     lcd_puts("    ");
     
     //Display value in hexa
     itoa(value, lcd_string, 16);  // Convert decimal value to string
     lcd_gotoxy(13,0);
     lcd_puts(lcd_string);
     
     //Display which button was pressed
     lcd_gotoxy(8,1);
     lcd_puts("    ");
     lcd_gotoxy(12,1);
     lcd_puts("    ");

     lcd_gotoxy(8, 1);
     itoa(value, lcd_string, 10);
     if (value>1000) {
     lcd_puts("none");
     } else if ((value>600)&&(value<1000)) {
     lcd_puts("Select");
     } else if ((value>350)&&(value<450)) {
     lcd_puts("Left");
     } else if ((value>200)&&(value<270)) {
     lcd_puts("Down");
     } else if ((value>5)&&(value<120)) {
     lcd_puts("Up");
     } else if (value==0) {
     lcd_puts("Right");
     }

}
```

### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![Data](Images/Data.png)

2. Flowchart figure for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![Flowchart](Images/Flowchart.png)

### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![Scheme](Images/Scheme.png)
