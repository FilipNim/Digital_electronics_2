vzpocitana u    
0 		
0,495	
1,203           
1,97
3,182
5

ADC:         merena
0V 0		0
0,495 101	99
1,203 246	257
1,97  403	410
3,182 651	640
5     1023	1023

   | **Operation** | **Register(s)** | **Bit(s)** | **Description** |
   | :-- | :-: | :-: | :-- |
   | Voltage reference    | ADMUX | REFS1:0 | 00: ..., 01: AVcc voltage reference (5V), ... |
   | Input channel        | ADMUX | MUX3:0 | 0000: ADC0, 0001: ADC1, ... |
   | ADC enable           | ADCSRA | ADEN | 0-enable, 1- disable |
   | Start conversion     | ADCSRA | ADSC | 1 - conversion is in progress When the conversion is complete, it returns to zero|
   | ADC interrupt enable | ADCSRA | ADIE |  |
   | ADC clock prescaler  |  | ADPS2:0 | 000: Division factor 2, 001: 2, 010: 4, ...|
   | ADC 10-bit result    |  |  |  |