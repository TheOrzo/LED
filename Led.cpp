#include "Led.h"

Led::Led(gpio_num_t gpioPin, bool invert) : pin(gpioPin), invert(invert)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    setState(OFF);
}

void Led::setInvert(bool invert)
{
    this->invert = invert;
}

void Led::setState(led_state state)
{
    if (invert) {
        this->state = !state;
    } else {
        this->state = state;
    }
    gpio_set_level(pin, this->state);
}

void Led::toggle()
{
    state = !state;
    gpio_set_level(pin, state);
}