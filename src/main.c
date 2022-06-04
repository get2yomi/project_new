
#include "stm32f411xe.h"
#include "stdarg.h"
#include "stdio.h"
#include "onboard_led_test.h"
#include "FreeRTOS.h"
#include "task.h"



TaskHandle_t myTask1Handle = NULL;
void myTask1 (void *pvParameters );



void myTask1 (void *pvParameters ){

while (1){

	GPIOC->BSRR |= GPIO_BSRR_BR_13;
	vTaskDelay(50);
	GPIOC->BSRR |= GPIO_BSRR_BS_13;
		vTaskDelay(50);
}

}


 int main(void){
	system_coreclock_cofig();   // changing clock speed to 100mhz
	led_inti();                 // init onboard led to test code
  xTaskCreate (myTask1,"task1",configMINIMAL_STACK_SIZE,(void*) 0,1, NULL);
 //xTaskCreate (myTask1,"task1", 200,(void*) 0,tskIDLE_PRIORITY, &myTask1Handle);
	vTaskStartScheduler();
//return 0;
  /* Infinite loop */
while (1){
	
}

}



