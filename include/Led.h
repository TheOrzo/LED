#include "driver/gpio.h"



class Led 
{
    typedef uint32_t led_state;

    public: 
        static const led_state OFF = 0;
        static const led_state ON = 1;

        Led(gpio_num_t pin, bool invert = true);

        void setState(led_state state);
        void toggle();
        void setInvert(bool invert);

    private:
        gpio_num_t pin;

        led_state state = OFF;
        bool invert = true;
    
};