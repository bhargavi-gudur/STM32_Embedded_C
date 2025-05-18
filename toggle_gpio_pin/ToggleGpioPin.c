/**
 * @file ToggleGpioPin.c
 * @author Gandla bhargavi
 * @brief GPIO pin toggle example for STM32F105 microcontroller
 * @version 0.1
 * @date 2025-05-18
 * 
 */


#include "stm32f10x.h"  // Include STM32F105 header file

/**
 * @brief  Enables GPIOA clock.
 * @note   This function modifies the APB2ENR register to enable GPIOA.
 */
void GPIO_Enable() {
    RCC->APB2ENR |= (1 << 2);  // Enable GPIOA clock
}

/**
 * @brief  Initializes PA9 as output.
 * @note   Configures PA9 as a push-pull output with 50MHz speed.
 */
void GPIO_Init() {
    GPIOA->CRH &= ~(0xF << 4);  // Clear previous settings for PA9
    GPIOA->CRH |= (0x3 << 4);   // Set PA9 as output push-pull, max speed 50MHz
}

/**
 * @brief  Toggles PA9.
 * @note   This function modifies the ODR register to change pin state.
 */
void GPIO_Toggle() {
    GPIOA->ODR ^= (1 << 9);  // Toggle PA9
}

/**
 * @brief  Simple delay function.
 * 
 */
void delay() {
    for (volatile int i = 0; i < 500000; i++);  // Basic delay loop
}

/**
 * @brief  Main function.
 * @note   Calls GPIO initialization and continuously toggles PA9.
 * @retval int (0 for success)
 */
int main() {
    GPIO_Enable();
    GPIO_Init();

    while (1) {
        GPIO_Toggle();
        delay();
    }
}
