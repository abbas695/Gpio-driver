#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"


int main(void)
{
	KeyPad_INIT();
	while(1)
	{
		KeyPad_MANAGE();

	}

}
