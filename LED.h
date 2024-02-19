#ifndef LED_H
#define LED_H

#include <stdint.h>

// LED definitions
#define PORTN_D1 0b00000010
#define PORTN_D2 0b00000001
#define PORTF_D3 0b00010000
#define PORTF_D4 0b00000001
#define LED_OFF 0b00000000

// Function prototypes
void PortN_Init(void);
void PortF_Init(void);
void Init_All(void);
void Init_D1(void);
void Init_D2(void);
void Init_D3(void);
void Init_D4(void);
void LED_Control(uint8_t ledNumber, uint8_t state);

#endif // LED_H
