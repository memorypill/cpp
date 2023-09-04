#include <cstdint>
#include <iostream>
#include <typeinfo>

void integer_types_example()
{
	// ===== 1 bit =====
	bool u1 = true; // 0...1

	// ===== 1 byte =====
	char i8 = -128; // -128...127. Synonyms: [signed char]
	unsigned char u8 = 255; // 0...255

	// ===== 2 bytes =====
	short i16 = -32'768; // -32768...32767. Synonyms: [short int], [signed short], [signed short int].
	unsigned short u16 = 65'535; // 0...65535. Synonym: [unsigned short int].

	// ===== 2 or 4 bytes =====
	int i16_or_i32 = -32'768; // at least -32768...32767. Synonyms: [signed], [signed int].
	unsigned int u16_or_u32 = 65'535; // at least 0...65535. Synonym: [unsigned].

	// ===== 4 or 8 bytes =====
	long i32_or_i64 = -2'147'483'648L; // at least -2147483648...2147483647. Synonyms: [long int], [signed long], [signed long int].
	unsigned long u32_or_u64 = 4'294'967'295UL; // at least 0...4294967295. Synonym: [unsigned long int].

	// ===== 8 bytes =====
	long long i64 = -9'223'372'036'854'775'807LL; // -9223372036854775807...9223372036854775807. Synonyms: [signed long long], [signed long long int].
	unsigned long long u64 = 18'446'744'073'709'551'615ULL; // 0...18446744073709551615. Synonym: [unsigned long long int].

	// fixed size
	int8_t i8_t = i8;
	int16_t i16_t = i16;
	int32_t i32_t = -2'147'483'648L;
	int64_t i64_t = i64;

	uint8_t u8_t = u8;
	uint16_t u16_t = u16;
	uint32_t u32_t = 4'294'967'295UL;
	uint64_t u64_t = u64;
}

void fractional_types_example()
{
	// Approximate normal: ±1.175,494,3*10-38...±3.402,823,4*10+38
	// Approximate subnormal: ±1.401,298,4*10-45
	// Exact normal: ±0x1p−126...±0x1.fffffep+127
	// Exact subnormal: ±0x1p−149
	float f32 = 1.175'494'3E-38F;
	
	// Approximate normal: ±2.225,073,858,507,201,4*10-308...±1.797,693,134,862,315,7*10+308
	// Approximate subnormal: 4.940,656,458,412*10-324
	// Exact normal: ±0x1p−1022...±0x1.fffffffffffffp+1023
	// Exact subnormal: ±0x1p−1074
	double f64 = 2.225'073'858'507'201'4E-308;

	long double f64_128 = f64;
}

void numeration_system_example()
{
	int binary = 0b11111111; // 255
	int octal = 0377; // 255
	int decimal = 255;
	int hexadecimal = 0xFF; // = 255
}

void auto_example()
{
	auto i = 1; // int
}

void types_size_example()
{
	std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
	std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;

	std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
	std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
	std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
}

void alphanumeric_example()
{
	const char ch8 = 'a';
	const char* c_style_string = "test";

	wchar_t wch16{ L'a' };

	char16_t ch16{ u'a' }; // unsigned
	char32_t ch32{ U'a' }; // signed!

	std::string std_string = c_style_string;
	const char* c_style_string_pointer = std_string.c_str();
}


void typeid_example()
{
	std::cout << "typeid_example" << std::endl;

	float float_value = 1.0f;

	const std::type_info& double_type_info = typeid(double);

	const std::type_info& float_type_info = typeid(float_value);

	if (double_type_info != float_type_info)
	{
		std::cout << "double_type_info != float_type_info" << std::endl;
	}

	std::cout << "double_type_info.name(): " << double_type_info.name() << std::endl;
	std::cout << "float_type_info.raw_name(): " << float_type_info.raw_name() << std::endl;
}