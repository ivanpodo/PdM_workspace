/**
 ******************************************************************************
 * @file    PdM_workspace/practica-5/Src/main.c
 * @author  Iván Podoroska
 * @brief   This program is a solution to practice 5.1 and 5.2 of the
 * Microcontroller Programming Course.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "API_uart.h"
#include "API_debounce.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define START_DELAY_INDEX 	0U
#define PERIOD_1 			100U
#define PERIOD_2 			500U

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void InitLEDs(void);
static void ToggleLEDs(void);

/* Private functions ---------------------------------------------------------*/
static void InitLEDs(void)
{
	BSP_LED_Init(LED1);
	BSP_LED_Init(LED2);
	BSP_LED_Init(LED3);
}

static void ToggleLEDs(void)
{
	BSP_LED_Toggle(LED1);
	BSP_LED_Toggle(LED2);
	BSP_LED_Toggle(LED3);
}

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void)
{
	/* STM32F4xx HAL library initialization:
		 - Configure the Flash prefetch
		 - Systick timer is configured by default as source of time base, but user
		   can eventually implement his proper time base source (a general purpose
		   timer for example or other time source), keeping in mind that Time base
		   duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and
		   handled in milliseconds basis.
		 - Set NVIC Group Priority to 4
		 - Low Level Initialization
	   */
	HAL_Init();

	/* Configure the system clock to 180 MHz */
	SystemClock_Config();

	/* Local variables declaration and initialization*/
	uint32_t blinkDurations[] = {PERIOD_1, PERIOD_2};
	uint8_t	blinkCount = sizeof(blinkDurations) / sizeof(uint32_t);
	delay_t blinkDelayStr[blinkCount];

	uint8_t runningDelay = START_DELAY_INDEX;

	if(uartInit() != true)
	{
		Error_Handler();
	}

	for (uint8_t i = 0U; i < blinkCount; i++)
	{
		delayInit(&blinkDelayStr[i], blinkDurations[i]);	
	}

	InitLEDs();

	debounceFSM_init();

	/* Infinite loop */
	while (1)
	{
		debounceFSM_update();

		if (readKey())
		{
			runningDelay++;

			if (runningDelay > (blinkCount - 1U))
			{
				runningDelay = START_DELAY_INDEX;
			}
		}

		if(delayRead(&blinkDelayStr[runningDelay]))
		{
			ToggleLEDs();
		}		
	}
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 180000000
 *            HCLK(Hz)                       = 180000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 8
 *            PLL_N                          = 360
 *            PLL_P                          = 2
 *            PLL_Q                          = 7
 *            PLL_R                          = 2
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable Power Control clock */
	__HAL_RCC_PWR_CLK_ENABLE();

	/* The voltage scaling allows optimizing the power consumption when the device is
	   clocked below the maximum system frequency, to update the voltage scaling value
	   regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 360;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	if (HAL_PWREx_EnableOverDrive() != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	   clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}
}
/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void)
{
	/* Turn LED2 on */
	BSP_LED_On(LED2);
	while (1)
	{
	}
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
