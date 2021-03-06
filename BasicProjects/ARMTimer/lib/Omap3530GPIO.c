/*
 * Omap3530GPIO.c
 *
 *  Created on: 15 Mar 2017
 *      Author: Mathias
 */

#include <includes/Common.h>
#include <includes/Omap3530GPIO.h>

void digitalWrite(uint8_t pin, uint8_t val)
{
    uint32_t* out = (uint32_t*) (GPIO_BASE_ADDR(pin) + GPIO_DATAOUT);

    if (val == LOW)
    {
        bitSet(*out, GPIO_PIN_POS(pin));
    }
    else
    {
        bitClear(*out, GPIO_PIN_POS(pin));
    }
}

uint8_t digitalRead(uint8_t pin)
{
    uint32_t* in = (uint32_t*) (GPIO_BASE_ADDR(pin) + GPIO_DATAIN);

    if (*in & GPIO_PIN_POS(pin))
    {
        return HIGH;
    }
    else
    {
        return LOW;
    }
}

void pinMode(uint8_t pin, uint8_t mode)
{
    uint32_t* gpio_dir_ctr = (uint32_t*)  (GPIO_BASE_ADDR(pin) + GPIO_OE);

    if (mode == INPUT)
    {
        //*gpio_dir_ctr |= GPIO_PIN_POS(pin);
        bitSet(*gpio_dir_ctr, GPIO_PIN_POS(pin));
    }
    else
    {
        bitClear(*gpio_dir_ctr, GPIO_PIN_POS(pin));
    }
}

