#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "gpio_input.h"
#include "gpio_output.h"
#include "gpio_blinking_output.h"

using namespace std;

void gpioControllerTask();

// Inputs (Optocoupler):        17, 27, 23, 22, 24, 25, 8, 7
// Outputs (Open Collector):    6, 5, 1, 0
// Outputs (Relay):             26, 20, 16

GPIO_Input in1(17);
GPIO_Input in2(27);
GPIO_Input in3(23);
GPIO_Input in4(22);
GPIO_Input in5(24);
GPIO_Input in6(25);
GPIO_Input in7(8);
GPIO_Input in8(7);

GPIO_Output out1(6);
GPIO_Output out2(5);
GPIO_Output out3(1);
GPIO_Output out4(0);

GPIO_BlinkingOutput relay1(26);
GPIO_BlinkingOutput relay2(20);
GPIO_BlinkingOutput relay3(16);

void gpioControllerTask();

int main(int argc, char* argv[]) {
    std::thread gpioControllerThread(gpioControllerTask);

    gpioControllerThread.join();

    return EXIT_SUCCESS;
}

void gpioControllerTask() {
    relay1.blink();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    relay2.blink();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    relay3.blink();

    uint32_t i = 0;
    while (true) {
        out1.write(i & 1 << 0);
        out2.write(i & 1 << 1);
        out3.write(i & 1 << 2);
        out4.write(i & 1 << 3);
        ++i;
        std::cout << in1.read() << " " << in2.read() << " " << in3.read() << " " << in4.read() << " " << in5.read() << " " << in6.read() << " " << in7.read() << " " << in8.read() << " " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
