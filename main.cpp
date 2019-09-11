#include <iostream>
#include <mutex>
#include "ThreadLib.h"

int main() {
    std::mutex mtx;
    size_t i = 0;

    parallel_for(10000, [&i, &mtx](int j) {
        std::unique_lock<std::mutex> lck(mtx);
        i++;
        });

    std::cout << i << std::endl;
    return 0;
}