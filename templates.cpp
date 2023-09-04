#include <iostream>
#include <vector>

// !!! requires
// !!! concept
// !!! auto

// Templates

template <typename T>
// template <class T> - the same
const T& max1(const T& a, const T& b)
{
	return (a > b) ? a : b;
}


template <typename T, int array_size>
int get_first_zero(const T& array)
{
	for (int i = 0; i < array_size; i++)
	{
		if (0 == array[i])
			return i;
	}

	return -1;
}
//
//template<>
//int get_first_zero<int[3], 4>(const int[3] array)
//{
//	for (int i = 0; i < array_size; i++)
//	{
//		if (0 == array[i])
//			return i;
//	}
//
//	return -1;
//}

//template <class ...T>
//void fun1()
//{
//
//}

template<class T, int retry_count>
void print_n_times(T t)
{
	for (int i = 0; i < retry_count; i++)
	{
		std::cout << t << std::endl;
	}
}

template<int retry_count>
void print_n_times(double t)
{
	for (int i = 0; i < retry_count; i++)
	{
		std::cout << std::scientific << t << std::endl;
	}
}


template <class T>
void print_value(T value)
{
	std::cout << std::scientific << value << '\n';
}

template <class T = char>
void print_value2(T value)
{
	std::cout << "symbol: " << value << '\n';
}

template <>
void print_value<double>(double value)
{
	std::cout << std::scientific << value << '\n';
}

// template with ...

template<typename T>
int sum(T t)
{
	return t;
}

template<typename TFirst, typename... TRest>
int sum(TFirst first, TRest... rest)
{
	return first + sum(rest...);
}

template<typename... T>
void fun1(T... t)
{
	int res = sum(t...);
	std::cout << res << std::endl;
}


template<typename T, template<typename U, int I> class Arr>
void fun10(T t, Arr<T, 10> arr)
{

}

template<typename T>
auto add(const T& a, const T& b) -> decltype(a + b) {
	return a + b;
}


//template <typename T> requires std::is_same<T, int>::value
//T sum(T a, T b)
//{
//	return a + b;
//}

//template <typename T>
//concept size = sizeof(T) <= sizeof(int);

// Шаблон, принимает шаблонный класс
template <typename T>
class InnerClass
{
public:
	using Type = std::vector<T>;
};

template <template<class> class T>
class C
{
public:
	typename T<int>::Type T1;
};