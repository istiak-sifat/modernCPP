#include <iostream>
#include <thread>
#include <chrono>

void task() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Running in thread...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::jthread jt(task); // Starts the thread and automatically joins on scope exit

    std::cout << "Main thread continues...\n";

    return 0; // No need to call jt.join(), it will auto-join
}
