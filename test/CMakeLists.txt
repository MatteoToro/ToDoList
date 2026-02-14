include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
        Test.cpp
        TaskTest.cpp


)

target_link_libraries(tests
        todolist_lib
        gtest
        gtest_main
)

add_test(NAME AllTests COMMAND tests)
