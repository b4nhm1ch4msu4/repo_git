#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

int main() {
    std::ofstream serial("/dev/pts/4"); // Thay bằng cổng đầu của socat

    if (!serial.is_open()) {
        std::cerr << "Không mở được serial port.\n";
        return 1;
    }

    int temp = 25;
    while (true) {
        serial << "TEMP:" << temp++ << "C\n";
        serial.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

