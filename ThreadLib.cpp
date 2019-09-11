#include <thread>
#include <vector>
#include "ThreadLib.h"

void parallel_for(size_t iter, std::function<void(int)> f) {
    std::vector<std::thread> threads;
    auto nthreads = std::thread::hardware_concurrency();

    for (unsigned int i = 0; i < nthreads; i++) {
        threads.emplace_back([i, iter, nthreads, &f] {
            for (size_t j = i; j < iter; j += nthreads) {
                f(j);
            }
        });
    }

    for (auto &it : threads) {
        it.join();
    }
}
