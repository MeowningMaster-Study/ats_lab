#pragma once
#include <functional>
#include <chrono>
using namespace std;
using namespace std::chrono;

// вимірює час виконання функції
nanoseconds measure_duration(function<void()> f) {
    auto clock = high_resolution_clock();
    auto start = clock.now();
    f();
    auto stop =  clock.now();
    return stop - start;
}