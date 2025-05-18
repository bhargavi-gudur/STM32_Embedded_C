/**
 * @file gpio_pin.c
 * @author Gandla bhargavi
 * @brief  GPIO pin control for STM32F105 microcontroller
 * @details This code initializes GPIO pin PA9 as an output
 * and toggles its state in an infinite loop.
 * @version 0.1
 * @date 2025-05-18
 *
 */
#include "stm32f10x.h"  // STM32F105 standard peripheral library header

/**
 * @brief RCC APB2 peripheral clock enable register
 *
 */
#define RCC_APB2ENR (*((volatile uint32_t *)0x40021018))           // RCC APB2 peripheral clock enable register
#define GPIOA_CRH     (*((volatile uint32_t*)(GPIOA_BASE + 0x04))) // GPIOA control register high
#define GPIOA_ODR     (*((volatile uint32_t*)(GPIOA_BASE + 0x0C))) // GPIOA output data register

/**
 * @brief  Enable GPIOA clock
 * @details This function enables the clock for GPIOA
 * by setting the appropriate bit in the RCC_APB2ENR register.
 *
 */
void GPIO_Enable() {
    RCC_APB2ENR |= (1 << 2);  // Enable GPIOA clock
}
/**
 * @brief  Initialize GPIOA pin 9 as output
 * @details This function configures GPIOA pin 9 as a
 * push-pull output with a maximum speed of 50MHz.
 *
 */
void GPIO_Init() {
    GPIOA_CRH &= ~(0xF << 4);  // Clear previous settings for PA9
    GPIOA_CRH |= (0x3 << 4);   // Set PA9 as output (push-pull, 50MHz)
}

/**
 * @brief Toggle GPIOA pin 9
 * @details This function toggles the state of GPIOA pin 9
 * by using the XOR operation on the output data register.
 * @note This function is called in an infinite loop to create a
 * blinking effect.
 *
 */
void GPIO_Toggle() {
    GPIOA_ODR ^= (1 << 9);  // Toggle PA9
}

/**
 * @brief  Main function
 * @details This function initializes the GPIO pin and enters an infinite loop
 *          to toggle the pin state.
 * @return int
 */
int main() {
    GPIO_Enable();
    GPIO_Init();

    while (1) {
        GPIO_Toggle();
        for (volatile int i = 0; i < 1000000; i++);  // Simple delay
    }
}
