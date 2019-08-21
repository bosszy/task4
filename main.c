#include "pwm.h"
#include "sys.h"
#include "led.h"
#include "delay.h"

int main (void)
{	
	u8 i=1;
	u16 pwml;
	delay_init();
	LED_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	TIM3_PWM_Init(899,0);
	while(1)
	{
		delay_ms(10);
		if(i) pwml++;
		else pwml--;
		
		if(pwml>300) i=0;
		if(pwml==0) i=1;
		TIM_SetCompare2(TIM3,pwml);
	}
}

