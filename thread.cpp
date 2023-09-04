#include <iostream>
#include <thread>

thread_local int thread_local_variable = 0;

void incrementAndPrint()
{
    thread_local_variable++;
    thread_local_variable++;

    std::cout << "Thread ID: " << std::this_thread::get_id() << ", Thread-local variable: " << thread_local_variable << std::endl;
}

void thread_example()
{
    std::thread thread1(incrementAndPrint);
    std::thread thread2(incrementAndPrint);

    // Wait for the threads to finish
    thread1.join();
    thread2.join();
}