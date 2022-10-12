#ifndef GPIO_H
#define GPIO_H

#include <cstdint>

#include <gpiod.h>

class GPIO {
protected:
    static constexpr int chip = 0;
    static constexpr const char* consumer = "gpioBoardTest";

    uint32_t line;
    struct gpiod_chip* gpiodchip;
    struct gpiod_line* gpiodline;

protected:
    GPIO(const uint32_t line) noexcept;

public:
    virtual ~GPIO();
};

#endif
