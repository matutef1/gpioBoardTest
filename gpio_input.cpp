#include "gpio_input.h"

GPIO_Input::GPIO_Input(const uint32_t line) noexcept : GPIO(line) {
    gpiod_line_request_input(gpiodline, consumer);
}

bool GPIO_Input::read() const noexcept {
    return (gpiod_line_get_value(gpiodline) != 0);
}
