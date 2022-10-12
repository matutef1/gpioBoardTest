#include <chrono>

#include "gpio_blinking_output.h"

GPIO_BlinkingOutput::GPIO_BlinkingOutput(const uint32_t line) noexcept : GPIO_Output(line) {
    endBlink = false;
}

void GPIO_BlinkingOutput::on() noexcept {
    write(true);
}

void GPIO_BlinkingOutput::off() noexcept {
    write(false);
}

void GPIO_BlinkingOutput::write(const bool value) noexcept {
    endBlink = true;
    if (blinkThread.joinable())
        blinkThread.join();
    endBlink = false;

    gpiod_line_set_value(gpiodline, value ? 1 : 0);
}

void GPIO_BlinkingOutput::blink(const uint32_t n, const uint32_t t) noexcept {
    blink(n, t, t);
}

void GPIO_BlinkingOutput::blink(const uint32_t n, const uint32_t tOn, const uint32_t tOff) noexcept {
    endBlink = true;
    if (blinkThread.joinable())
        blinkThread.join();
    endBlink = false;

    blinkThread = std::thread([=] { blinkTask(n, tOn, tOff); });
}

void GPIO_BlinkingOutput::blinkTask(const uint32_t n, const uint32_t tOn, const uint32_t tOff) const noexcept {
    uint32_t i = 0;
    while (!endBlink && (i < n || n == permBlinkN)) {
        GPIO_Output::write(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(tOn));
        GPIO_Output::write(false);
        std::this_thread::sleep_for(std::chrono::milliseconds(tOff));
        if (n != permBlinkN)
            ++i;
    }
}
