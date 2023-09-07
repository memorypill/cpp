#include <iostream>
#include <future>

std::future<void> async_task()
{
    return std::async(std::launch::async, []
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "task completed !" << std::endl;
        });
}

void future_example()
{
    std::cout << "future_example" << std::endl;

    async_task().get();

    std::future<int> future_result = std::async([]() {
        return 42;
        });

    int result = future_result.get();

    std::cout << "result: " << result << std::endl;
}