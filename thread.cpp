#include <iostream>
#include <thread>

int variable = 0;
thread_local int thread_local_variable = 0;

void incrementAndPrint()
{
    variable++;
    variable++;

    thread_local_variable++;
    thread_local_variable++;

    std::cout << "Thread ID: " << std::this_thread::get_id() << ", thread_local variable: " << thread_local_variable << ", regular variable: " << variable << std::endl;
}

void thread_example()
{
    std::thread thread1(incrementAndPrint);
    thread1.join();

    std::thread thread2(incrementAndPrint);
    thread2.join();
}