/*
====================================== OpenMP Example ======================================
OpenMP is an alternative to the C++ standard library for parallel programming.
It provides a simpler way to write parallel code using compiler directives.
This example demonstrates how to use OpenMP to parallelize a loop.

"#pragma omp parallel for" means the following loop with be autonmatically parallized between all available threads.
"#pragma omp critical" means that the code will only be executed by one thread at a time

Note: you will need to compile and run in the terminal with the command:
    - g++ -fopenmp main.cpp -o main
    - ./main
*/


#include <iostream>
#include <omp.h> // NEW library!
#include <chrono>
#include <cmath> 

int main() {
    // Set the number of threads to use
    omp_set_num_threads(16);

    // Example 1: Displaying thread information   
    #pragma omp parallel for
    for (int i = 0; i < 8; ++i) {
        #pragma omp critical
        {
            std::cout << "Thread " << omp_get_thread_num() << " processing i = " << i << std::endl;
        }
    } 


/* 
    // Example 2: Parallelizing a loop with OpenMP
    // Try usign pragma omp parallel for and see how it affects the time taken
    // Try experimenting with the number of threads as well
    auto start_time = std::chrono::high_resolution_clock::now();
    int sum = 0;

    // Some loop
    for (int i = 0; i < 100000000; ++i) {
        sum += std::sqrt(i) + std::sin(i) + std::cos(i);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl; 
*/

    return 0;
}