#ifndef GPIO_INPUT_H
#define GPIO_INPUT_H

#include "gpio.h"

class GPIO_Input : public GPIO {
public:
    GPIO_Input(const uint32_t line) noexcept;

    virtual bool read() const noexcept;
};

#endif
