#include "gpio.h"

GPIO::GPIO(const uint32_t line) noexcept : line(line) {
    gpiodchip = gpiod_chip_open_by_number(chip);
    gpiodline = gpiod_chip_get_line(gpiodchip, line);
}

GPIO::~GPIO() {
    gpiod_chip_close(gpiodchip);
}
