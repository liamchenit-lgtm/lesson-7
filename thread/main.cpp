// ========================== 1) Computer Hardware Vocabulary ==========================
/*
CPU (Central Processing Unit): The main component of a computer that performs calculations and executes instructions.
    - Analogy -> Brain
RAM (Random Access Memory): Temporary storage that holds data and instructions for the CPU while a computer is running.
    - Analogy -> Short-term memory
Storage: Devices like hard drives or SSDs that store data permanently.
    - Analogy -> Long-term memory
*/ 


// ========================== 2) What is Multithreading? ==========================
/*
Core: A core is a single processing unit within a CPU that can execute instructions independently.
    - Analogy -> A chef in a kitchen (kitchen = brain)
Thread: A thread is a sequence of smaller tasks from a larger program.
    - Analogy -> Meal order

Serial: Tasks are performed one after another.
    - Analogy -> A single chef cooking one dish at a time
Parallel: Tasks are performed simultaneously by multiple cores.
    - Analogy -> Multiple chefs cooking different dishes at the same time

Multithreading: The ability of a CPU to execute multiple threads simultaneously, improving performance and responsiveness.
    - Analogy -> A restaurant with multiple chefs handling different orders at once
*/


// ========================== 3) When to Use Multithreading ==========================
/*
Advantages:
    - 
Disadvantages:
    - 

When to Use Multithreading:
    - When tasks can be performed independently and simultaneously.
    - When you need to run background tasks without blocking the main thread.
    - When performance needs to be improved by utilizing multiple CPU cores.
When not to Use Multithreading:
    - When tasks are heavily dependent on each other 
    - When the overhead of managing threads outweighs the benefits (dont use on small projects)
*/


// ========================== 3) Using <thread> ==========================
/*
<thread> is a C++ standard library header that provides support for multithreading.
It allows you to create and manage threads, enabling parallel execution of tasks.
There are a few important functions and classes in <thread>:

std::thread::hardware_concurrency
    - Returns the number of hardware threads available.

std::thread: 
    - Creates a new thread and begins executing it

std::thread::join
    - Blocks the code until the specified thread finishes
std::thread::detach
    - Allows the thread to run independently (non-blocking)
Note: You MUST use either join or detach, nut NOT both

std::this_thread::sleep_for
    - Pauses the current thread for a specified duration.

std::this_thread::get_id
    - gets unique ID of the current thread
    - Mostly for debugging purposes
*/


#include <iostream>
#include <thread> // used for multithreading
#include <chrono> // used for time-related functions

// Function that blinks a light on and off every second
void blink_light() {
    while (true) { // Blink 5 times
        std::cout << "[Light] ON" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "[Light] OFF" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Function that counts up every half second
void count_numbers() {
    int count = 1;
    while (true) { // Count to 10
        std::cout << "[Count] " << count << std::endl;
        count++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


int main() {
    // prints out the number of hardware cores available
    // If you use any more cores than this, it will no longer be parallel
    std::cout << "Hardware cores: " << std::thread::hardware_concurrency() << std::endl;

    // Why does count_numbers never run?
    blink_light(); 
    count_numbers(); 

     
    // Create two threads 
    // note: they will start running immediately
    //std::thread light_thread(blink_light);
    //std::thread counter_thread(count_numbers);

    // What do you expect to see now?
    //light_thread.join();     // Waits for blink_light to finish 
    //counter_thread.join();   // Waits for count_numbers to finish

    // Only runs if both threads have finished
    std::cout << "Threads have finished." << std::endl;
}

/*
Practice:
    1) Modify the .join() calls to .detach() and see what happens. Why does it happen?
    2) Switch back to join. Try sleeping the main thread for 5 seconds before the counter_thread is executed. 
    3) Create 2 threads that count down from 20. Have one thread count the even numbers and the other count the odd numbers.
*/