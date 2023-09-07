cmake_minimum_required (VERSION 3.8)

project ("cpp_memorypill")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(my_module1
    "my_module1.ixx"
 "exceptions.cpp")

# Add source to this project's executable.
add_executable (cpp_memorypill "main.cpp"
	"preprocessor.cpp"
	"modules_and_namespaces.cpp"
	"fundamental_types.cpp"
	"fundamental_operators.cpp"
	"cycles.cpp"
	"ellipsis.cpp"
	"compile_time.cpp"
	"pointers_and_refs.cpp"
	"arrays.cpp"
	"enums.cpp"
	"union_vs_struct_vs_class.cpp"
	"constructors.cpp"
	"casts.cpp"
	"custom_operators.cpp"
	"inheritance_abstract_virtual_friend.cpp"
	"templates.cpp"
	"exceptions.cpp"
	"lambda.cpp"
	"coroutines.cpp"
	"thread.cpp"
	"future.cpp"
	 )

target_link_libraries(cpp_memorypill PRIVATE my_module1)