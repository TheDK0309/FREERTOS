/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdio.h>
#include <stdint.h>
#include "string.h"
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;

//Task functions prototypes
void vTask1_handler(void *params);
void vTask2_handler(void *params);

static void prvSetupHardware(void);
static void prvSetupUART(void);
void printmsg(char *msg);

#ifdef USE_SEMIHOSTING
	extern void initialise_monitor_handles();
#endif

char usr_msg[250]={0};
#define true 1
#define false 0
#define AVAILABLE true
#define NON_AVAILABLE false
uint8_t UART_ACCESS_KEY=AVAILABLE;

int main(void)
{
	#ifdef USE_SEMIHOSTING
		initialise_monitor_handles();

		printf("FReeRTOS 1st Example\n");
	#endif
	DWT->CTRL |= (1 << 0);//Enable CYCCNT in DWT_CTRL.


	RCC_DeInit();

	SystemCoreClockUpdate();

	prvSetupHardware();
	sprintf(usr_msg,"Starting");
	printmsg(usr_msg);

	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();

	xTaskCreate( vTask1_handler,"Task-1", configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle1 );

	xTaskCreate( vTask2_handler,"Task-2", configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle2 );

	vTaskStartScheduler();

	for(;;);
}
void vTask1_handler(void *params)
{
	while(1){
		if(UART_ACCESS_KEY==AVAILABLE){
			UART_ACCESS_KEY=NON_AVAILABLE;
			printmsg("Task1_Running\n");
			UART_ACCESS_KEY=AVAILABLE;
			SEGGER_SYSVIEW_Print("Task1 is yielding");
			traceISR_EXIT_TO_SCHEDULER();
			taskYIELD();
		}

	}
}
void vTask2_handler(void *params)
{
	while(1){
			if(UART_ACCESS_KEY==AVAILABLE){
				UART_ACCESS_KEY=NON_AVAILABLE;
				printmsg("Task2_Running\n");
				UART_ACCESS_KEY=AVAILABLE;
				SEGGER_SYSVIEW_Print("Task2 is yielding");
				traceISR_EXIT_TO_SCHEDULER();
				taskYIELD();
			}

		}

}
static void prvSetupUART(void){
		GPIO_InitTypeDef gpio_uart_pins;
		USART_InitTypeDef uart2_init;

		//Enable the UART2 and GPIOA Peripheral Clock
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

		memset(&gpio_uart_pins,0,sizeof(gpio_uart_pins));
		//Alternate function configuration of MCU pins to behave as UART2 TX and RX
		gpio_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
		gpio_uart_pins.GPIO_Mode= GPIO_Mode_AF;
		gpio_uart_pins.GPIO_PuPd=GPIO_PuPd_UP ;
		GPIO_Init(GPIOA,&gpio_uart_pins);

		//AF mode settings for the pins
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2);
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART3);

		//UART parameter initializations
		memset(&uart2_init,0,sizeof(uart2_init));

		uart2_init.USART_BaudRate=115200;
		uart2_init.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
		uart2_init.USART_Mode= USART_Mode_Rx | USART_Mode_Tx;
		uart2_init.USART_Parity=USART_Parity_No;
		uart2_init.USART_StopBits=USART_StopBits_1;
		uart2_init.USART_WordLength=USART_WordLength_8b;
		USART_Init(USART2,&uart2_init);

		//Enable UART peripheral command
		USART_Cmd(USART2,ENABLE);
}
static void prvSetupHardware(void){
	prvSetupUART();
}
void printmsg(char *msg){
	for(uint32_t i=0; i < strlen(msg); i++)
		{
			while ( USART_GetFlagStatus(USART2,USART_FLAG_TXE) != SET);
			USART_SendData(USART2,msg[i]);
		}

		while ( USART_GetFlagStatus(USART2,USART_FLAG_TC) != SET);
}

