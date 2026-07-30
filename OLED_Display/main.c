/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "ssd1306.h"
#include "fonts.h"

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

/* Function to draw smiley face */
void Draw_Smiley(void)
{
    /* Face outline */
    SSD1306_DrawCircle(64, 32, 25, SSD1306_COLOR_WHITE);

    /* Left eye */
    SSD1306_DrawFilledCircle(55, 25, 3, SSD1306_COLOR_WHITE);

    /* Right eye */
    SSD1306_DrawFilledCircle(73, 25, 3, SSD1306_COLOR_WHITE);

    /* Smile - draw several pixels */
    SSD1306_DrawLine(54, 40, 58, 44, SSD1306_COLOR_WHITE);
    SSD1306_DrawLine(58, 44, 64, 46, SSD1306_COLOR_WHITE);
    SSD1306_DrawLine(64, 46, 70, 44, SSD1306_COLOR_WHITE);
    SSD1306_DrawLine(70, 44, 74, 40, SSD1306_COLOR_WHITE);
}

/**
  * @brief  The application entry point.
  */
int main(void)
{
    /* Initialize HAL */
    HAL_Init();

    /* Configure system clock */
    SystemClock_Config();

    /* Initialize GPIO */
    MX_GPIO_Init();

    /* Initialize I2C */
    MX_I2C1_Init();

    /* Initialize OLED */
    SSD1306_Init();

    /* Clear OLED */
    SSD1306_Clear();

    /* Draw smiley face */
    Draw_Smiley();

    /* Update OLED display */
    SSD1306_UpdateScreen();

    /* Infinite loop */
    while (1)
    {
    }
}

/**
  * @brief System Clock Configuration
  */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK |
        RCC_CLOCKTYPE_SYSCLK |
        RCC_CLOCKTYPE_PCLK1 |
        RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief I2C1 Initialization Function
  */
static void MX_I2C1_Init(void)
{
    hi2c1.Instance = I2C1;

    hi2c1.Init.ClockSpeed = 400000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    if (HAL_I2C_Init(&hi2c1) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief GPIO Initialization Function
  */
static void MX_GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
}

/**
  * @brief Error Handler
  */
void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
    }
}
