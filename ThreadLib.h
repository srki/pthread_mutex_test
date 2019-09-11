#ifndef LOCK_TEST_THREADLIB_H
#define LOCK_TEST_THREADLIB_H

#include <functional>

void parallel_for(size_t iter, std::function<void(int)> f);

#endif //LOCK_TEST_THREADLIB_H
