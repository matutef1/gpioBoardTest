#ifndef GPIO_BLINKINGOUTPUT_H
#define GPIO_BLINKINGOUTPUT_H

#include <atomic>
#include <thread>

#include "gpio_output.h"

class GPIO_BlinkingOutput : GPIO_Output {
public:
    static inline constexpr uint32_t permBlinkN = 0;
    static inline constexpr uint32_t defaultBlinkN = permBlinkN;
    static inline constexpr uint32_t defaultBlinkT = 1000;

private:
    std::thread blinkThread;
    std::atomic_bool endBlink;

public:
    GPIO_BlinkingOutput(const uint32_t line) noexcept;

    void write(const bool value) noexcept;
    void on() noexcept;
    void off() noexcept;
    void blink(const uint32_t n = defaultBlinkN, const uint32_t t = defaultBlinkT) noexcept;
    void blink(const uint32_t n, const uint32_t tOn, const uint32_t tOff) noexcept;

private:
    void blinkTask(const uint32_t n, const uint32_t tOn, const uint32_t tOff) const noexcept;
};

#endif
