#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"


int main(void)
{
	GPIO_Init(GPIOB,5,1,1);
	GPIO_Init(GPIOB,6,1,1);
	GPIO_Init(GPIOB,7,1,1);
	GPIO_Init(GPIOB,3,0,1);
	GPIO_pull_up_down_mode(GPIOB,3,1);

	// super loop
	int count=1;
	while(1)
	{
		if (debounce(GPIOB,3)){

			switch(count){

			case 0:
				GPIO_Write(GPIOB,7,0);
				GPIO_Write(GPIOB,6,0);
				GPIO_Write(GPIOB,5,0);
				count=count + 1;
				break;
			case 1:
				GPIO_Write(GPIOB,5,1);
				count=count + 1;
				break;
			case 2:
				GPIO_Write(GPIOB,6,1);
				GPIO_Write(GPIOB,5,0);
				count=count + 1;
				break;
			case 3:
				GPIO_Write(GPIOB,5,1);
				count=count + 1;
				break;
			case 4:
				GPIO_Write(GPIOB,7,1);
				GPIO_Write(GPIOB,6,0);
				GPIO_Write(GPIOB,5,0);
				count=count + 1;
				break;
			case 5:
				GPIO_Write(GPIOB,5,1);
				count=count + 1;
				break;
			case 6:
				GPIO_Write(GPIOB,6,1);
				GPIO_Write(GPIOB,5,0);
				count=count + 1;
				break;
			case 7:
				GPIO_Write(GPIOB,5,1);
				count=0;
				break;
			}
		}

	}

}
