
#include <avr/io.h>
#include <util/delay.h>

void Timer0_PWM_Init(unsigned char set_duty_cycle)
{
	TCNT0 = 0; 

	OCR0  = set_duty_cycle; 
	DDRB  = DDRB | (1<<PB3);


	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

int main(void)
{
	unsigned char duty;
	while(1)
	{
		for(duty = 0 ; duty < 255 ; duty++)
		{
			
			Timer0_PWM_Init(duty);
			_delay_ms(10);
		}
		_delay_ms(100);
		for(duty = 255 ; duty > 0 ; duty--)
		{
			
			Timer0_PWM_Init(duty);
			_delay_ms(10);
		}
	}
}
