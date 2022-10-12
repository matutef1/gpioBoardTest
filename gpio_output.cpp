#include "gpio_output.h"

GPIO_Output::GPIO_Output(const uint32_t line) noexcept : GPIO(line) {
    gpiod_line_request_output(gpiodline, consumer, 0);
}

void GPIO_Output::write(const bool value) const noexcept {
    gpiod_line_set_value(gpiodline, value ? 1 : 0);
}
