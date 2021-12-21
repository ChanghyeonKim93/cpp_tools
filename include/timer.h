#ifndef _TIMER_WINDOWS_H_
#define _TIMER_WINDOWS_H_
#include <chrono>
#include <iostream>

auto start = std::chrono::high_resolution_clock::now();
auto finish = std::chrono::high_resolution_clock::now();
auto gap = finish - start;

namespace util {
    /**
    *
    * @brief tic() function (same with MATLAB 'tic')
    * @details This function stores a current time in global variable 'start'.
    * @return none.
    */
    void tic() {
        start = std::chrono::high_resolution_clock::now();
    }

    /**
    *
    * @brief toc() function (same with MATLAB 'toc')
    * @details This function prints elapsed time from the moment that the last 'tic()' was executed. (double-type)
    * @return elapsed time [ms] (double-type)
    */
    double toc(bool flag_verbose) {
        finish = std::chrono::high_resolution_clock::now();
        gap = finish - start;
        if (flag_verbose) {
            std::cout << "exec time: " << (double)(gap / std::chrono::microseconds(1)) / 1000.0 << "[ms]" << std::endl;
        }
        return (double)(gap / std::chrono::microseconds(1)) / 1000.0;
    }
}
#endif