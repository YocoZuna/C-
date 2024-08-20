/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "eth.h"
#include "i2c.h"
#include "rtc.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"
#include <stdio.h>
#include <string.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
RTC_TimeTypeDef sTime = {.Hours=7,.Minutes=13,.Seconds=0,.StoreOperation= RTC_STOREOPERATION_RESET,.DayLightSaving=RTC_DAYLIGHTSAVING_NONE};
/* USER CODE END PFP */
char kuts[50];
/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void SetCalendarAlarm(void);
void Enter_StopMode(void);
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ETH_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_I2C1_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
	RTC_TimeTypeDef currentTime;
	HAL_RTC_GetTime(&hrtc, &currentTime, RTC_FORMAT_BIN);
	sprintf(kuts,"I've wake up biacz %d:%d:%d\n\r",currentTime.Hours,currentTime.Minutes,currentTime.Seconds);
	HAL_UART_Transmit(&huart3, (uint8_t*)kuts, strlen(kuts), 1000);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


	  HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
	  Enter_StopMode();
	  HAL_UART_Transmit(&huart3, (uint8_t*)kuts, strlen(kuts), 1000);
	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void Enter_StopMode(void)
{


	EXTI_HandleTypeDef ee = {.Line = EXTI_LINE_17,.PendingCallback = NULL};
	HAL_EXTI_ClearPending(&ee,EXTI_TRIGGER_RISING);
	__HAL_RTC_ALARM_CLEAR_FLAG(&hrtc,RTC_FLAG_ALRAF);
	HAL_NVIC_ClearPendingIRQ(RTC_Alarm_IRQn);

	__HAL_GPIO_EXTI_CLEAR_IT(USER_Btn_Pin);
	HAL_NVIC_ClearPendingIRQ(EXTI15_10_IRQn);

	HAL_PWR_EnableSEVOnPend();
	SetCalendarAlarm();
	HAL_SuspendTick();
	memcpy(kuts,"",sizeof(kuts));

	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_UNDERDRIVE_ON, PWR_STOPENTRY_WFE);

	uint32_t e = HAL_NVIC_GetPendingIRQ(RTC_Alarm_IRQn) > HAL_NVIC_GetPendingIRQ(EXTI15_10_IRQn) ? 0x69 :0x70;

	if(e == 0x69){

		sprintf(kuts,"Waked from alarm\n\r");
	}
	else if(e==0x70){

		sprintf(kuts,"Waked from button\n\r");
	}

	HAL_ResumeTick();




	SystemClock_Config();
}


void SetCalendarAlarm(void)
{
	RTC_TimeTypeDef currentTime;
	HAL_RTC_GetTime(&hrtc, &currentTime, RTC_FORMAT_BIN);
	RTC_AlarmTypeDef sAlarm = {0};
	RTC_DateTypeDef currentDate;
	HAL_RTC_GetDate(&hrtc, &currentDate, RTC_FORMAT_BIN);
	sAlarm.AlarmTime.Hours = 0x0;
	sAlarm.AlarmTime.Minutes = currentTime.Minutes+10;
	sAlarm.AlarmTime.Seconds = 0x0;
	sAlarm.AlarmTime.SubSeconds = 0x0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	sAlarm.AlarmDateWeekDay = currentDate.Date;
	sAlarm.Alarm = RTC_ALARM_A;

	HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm,RTC_FORMAT_BIN);

}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
