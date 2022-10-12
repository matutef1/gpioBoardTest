#ifndef GPIO_OUTPUT_H
#define GPIO_OUTPUT_H

#include "gpio.h"

class GPIO_Output : public GPIO {
public:
    GPIO_Output(const uint32_t line) noexcept;

    virtual void write(const bool value) const noexcept;
};

#endif
