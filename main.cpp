#include <iostream>
#include "cpp_memorypill.h"

int main()
{
    // preprocessor
    conditional_compilation_example();
    macros_example();

    // modules_and_namespaces
    modules_and_namespaces();
    
    // fundamental_types
    types_size_example();
    typeid_example();

    // fundamental_operators
    fundamental_operators_example();
    precedence_example();

    // cycles
    cycles_example();

    // ellipsis
    ellipsis_example(3, 1, 2, 3);
    
    // compile_time
    compile_time_example();

    // pointers_and_refs
    poiners_example();
    refs_example();

    // arrays
    arrays_example();

    // enums
    enum_example();

    // union_vs_struct_vs_class
    unions_example();
    structs_example();

    // constructors
    explisit_constructor_example();
    deleted_copy_constructor_example();
    deleted_move_constructor_example();

    // casts
    casts_example();

    // custom_operators
    custom_operators_example();

    // inheritance_abstract_virtual_friend
    inheritance_example();

    // templates
    templates_example();

    // exceptions_
    exceptions_example();

    // lambda
    lambda_example();

    // coroutines
    coroutines_example();

    // thread
    thread_example();

    // future
    future_example();

    // unique_shared_weak_move_forward
    forward_example();

    return 0;
}
