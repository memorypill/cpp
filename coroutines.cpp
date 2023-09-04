#include <iostream>
#include <coroutine>

struct promise_type1;

class SimpleCoroutine
{
public:
    
    struct promise_type
    {
        int value;

        SimpleCoroutine get_return_object();
        std::suspend_always initial_suspend();
        std::suspend_always final_suspend() noexcept;

        void return_value(int val);
        std::suspend_always yield_value(int val);

        void unhandled_exception();
    };

    SimpleCoroutine(std::coroutine_handle<promise_type> h)
        : handle(h) {}

    ~SimpleCoroutine()
    {
        if (handle)
            handle.destroy();
    }

    bool move_next()
    {
        if (!handle.done())
        {
            handle.resume();
            return true;
        }

        return false;
    }

    int current_value() const
    {
        return handle.promise().value;
    }

private:
    std::coroutine_handle<promise_type> handle;
};

SimpleCoroutine SimpleCoroutine::promise_type::get_return_object()
{
    std::cout << "get_return_object" << std::endl;

    return SimpleCoroutine(std::coroutine_handle<promise_type>::from_promise(*this));
}

std::suspend_always SimpleCoroutine::promise_type::initial_suspend()
{
    std::cout << "initial_suspend" << std::endl;
    return {};
}

std::suspend_always SimpleCoroutine::promise_type::final_suspend() noexcept
{
    std::cout << "final_suspend" << std::endl;
    return {};
}

std::suspend_always SimpleCoroutine::promise_type::yield_value(int val)
{
    std::cout << "yield_value=" << val  << std::endl;
    value = val;
    return {};
}


void SimpleCoroutine::promise_type::return_value(int val)
{
    std::cout << "return_value=" << val << std::endl;
    value = val;
}

void SimpleCoroutine::promise_type::unhandled_exception()
{
    std::cout << "unhandled_exception" << std::endl;
}

SimpleCoroutine build_simple_coroutine()
{
    co_yield 1;
    co_yield 2;
    co_yield 3;

    co_await std::suspend_always{};

    co_return 4;
}

void coroutines_example()
{
    std::cout << "coroutines_example" << std::endl;

    SimpleCoroutine coroutine = build_simple_coroutine();

    while (coroutine.move_next())
    {
        std::cout << "Coroutine value: " << coroutine.current_value() << std::endl;
    }
}

