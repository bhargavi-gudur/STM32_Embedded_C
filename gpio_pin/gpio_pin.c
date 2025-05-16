#include "stm32f10x.h"  // STM32F105 standard peripheral library header

#define RCC_APB2ENR   (*((volatile uint32_t*)0x40021018)) // RCC APB2 peripheral clock enable register
//#define GPIOA_BASE     0x40010800
#define GPIOA_CRH     (*((volatile uint32_t*)(GPIOA_BASE + 0x04))) // GPIOA control register high
#define GPIOA_ODR     (*((volatile uint32_t*)(GPIOA_BASE + 0x0C))) // GPIOA output data register

void GPIO_Enable() {
    RCC_APB2ENR |= (1 << 2);  // Enable GPIOA clock
}

void GPIO_Init() {
    GPIOA_CRH &= ~(0xF << 4);  // Clear previous settings for PA9
    GPIOA_CRH |= (0x3 << 4);   // Set PA9 as output (push-pull, 50MHz)
}

void GPIO_Toggle() {
    GPIOA_ODR ^= (1 << 9);  // Toggle PA9
}

int main() {
    GPIO_Enable();
    GPIO_Init();

    while (1) {
        GPIO_Toggle();
        for (volatile int i = 0; i < 1000000; i++);  // Simple delay
    }
}
