

// clang-format off
#include "LED.h"
#include <stdint.h>
#include "tm4c1294ncpdt.h"
#include "Systick.h"
#include "PLL.h"
// clang-format on

// Turns on D1, D2
void PortN_Init(void)
{
    // activate the clock for Port N
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;
    // allow time for clock to stabilize
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12) == 0)
    {
    };
    // Make N0 & N1 outputs to turn on LEDs
    GPIO_PORTN_DIR_R = PORTN_D1 | PORTN_D2;
    // Enable
    GPIO_PORTN_DEN_R = PORTN_D1 | PORTN_D2;
    return;
}

// Turns on D3, D4
void PortF_Init(void)
{
    // activate the clock for Port F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    // allow time for clock to stabilize
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5) == 0)
    {
    };
    // Make F0 & F4 outputs to turn on LEDs
    GPIO_PORTF_DIR_R = PORTF_D3 | PORTF_D4;
    // Enable
    GPIO_PORTF_DEN_R = PORTF_D3 | PORTF_D4;
    return;
}

void Init_All(void)
{
    PortN_Init();
    PortF_Init();
    return;
}

void Init_D1(void)
{
    // activate the clock for Port N
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;
    // allow time for clock to stabilize
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12) == 0)
    {
    };
    // Make N0 & N1 outputs to turn on LEDs
    GPIO_PORTN_DIR_R = PORTN_D1;
    // Enable
    GPIO_PORTN_DEN_R = PORTN_D1;
    return;
}

void Init_D2(void)
{
    // activate the clock for Port N
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;
    // allow time for clock to stabilize
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12) == 0)
    {
    };
    // Make N0 & N1 outputs to turn on LEDs
    GPIO_PORTN_DIR_R = PORTN_D2;
    // Enable
    GPIO_PORTN_DEN_R = PORTN_D2;
    return;
}

void Init_D3(void)
{
    // activate the clock for Port F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    // allow time for clock to stabilize
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5) == 0)
    {
    };
    // Make F0 & F4 outputs to turn on LEDs
    GPIO_PORTF_DIR_R = PORTF_D3;
    // Enable
    GPIO_PORTF_DEN_R = PORTF_D3;
    return;
}

void Init_D4(void)
{
    // activate the clock for Port F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    // allow time for clock to stabilize
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5) == 0)
    {
    };
    // Make F0 & F4 outputs to turn on LEDs
    GPIO_PORTF_DIR_R = PORTF_D4;
    // Enable
    GPIO_PORTF_DEN_R = PORTF_D4;
    return;
}

void LED_Control(uint8_t ledNumber, uint8_t state)
{
    if (ledNumber == 1)
    {
        if (state == 1)
        {
            GPIO_PORTN_DATA_R |= PORTN_D1;
        }
        else
        {
            GPIO_PORTN_DATA_R &= ~PORTN_D1;
        }
    }
    else if (ledNumber == 2)
    {
        if (state == 1)
        {
            GPIO_PORTN_DATA_R |= PORTN_D2;
        }
        else
        {
            GPIO_PORTN_DATA_R &= ~PORTN_D2;
        }
    }
    else if (ledNumber == 3)
    {
        if (state == 1)
        {
            GPIO_PORTF_DATA_R |= PORTF_D3;
        }
        else
        {
            GPIO_PORTF_DATA_R &= ~PORTF_D3;
        }
    }
    else if (ledNumber == 4)
    {
        if (state == 1)
        {
            GPIO_PORTF_DATA_R |= PORTF_D4;
        }
        else
        {
            GPIO_PORTF_DATA_R &= ~PORTF_D4;
        }
    }
    return;
}