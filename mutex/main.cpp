// ========================== 4) Mutex ==========================
/*
Bonus:
    - What happens if 2 threads attempt to access the same variable at the same time?
    - How can you prevent this?
    - The solution is to use mutex

Option 1: mtx.lock() and mtx.unlock()
    - The manual way to lock and unlock a mutex
    - any code between these lines can only be accessed by one thread at a time
Option 2: std::lock_guard<std::mutex> lock(mtx);
    - The automatic way to lock and unlock a mutex
    - It locks the mutex when it is created and unlocks it when it goes out of scope
    - This is the preferred way to use mutexes as it prevents deadlocks
    - It is also less error-prone than using mtx.lock() and mtx.unlock()

Practice:
    1) Run the code below, is it what you expected?
    2) Use mtx.lock() and mtx.unlock() around the counter variable to prevent
        the threads from accessing it at the same time.
    3) What does the output look like now?
    4) Delete the mtx.lock() and mtx.unlock() calls. Add "std::lock_guard<std::mutex> lock(mtx);"
        at the beginning of the add() function. What does the output look like now?
*/

#include <iostream>
#include <thread>
#include <mutex> // new library!

int counter = 0; // Global counter
std::mutex mtx; // creates a mutex

// Function to add to the counter
void add() {
    for (int i = 0; i < 100; ++i) {
        counter++;
        std::cout << "Counter: " << counter << "\n";      
    }
}

int main() {
    std::thread t1(add);
    std::thread t2(add);

    t1.join();
    t2.join();

    std::cout << "Final counter: " << counter << "\n";
}