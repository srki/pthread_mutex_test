cmake_minimum_required(VERSION 3.1)
project(pthread_mutex_test)

add_library(thread_lib SHARED ThreadLib.cpp)

find_package(Threads REQUIRED)
target_link_libraries(thread_lib PRIVATE ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(thread_lib PUBLIC cxx_std_11)

add_executable(lock_test main.cpp)
target_link_libraries(lock_test thread_lib)