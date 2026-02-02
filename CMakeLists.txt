cmake_minimum_required(VERSION 3.30)
project(ToDoList)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Abilità il testing
enable_testing()



include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Evita warning su macOS
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


add_library(todolist_lib
        Task.cpp
        ToDoList.cpp
        Memoria.cpp
)

target_include_directories(todolist_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


add_executable(main_app
        main.cpp
)

target_link_libraries(main_app
        todolist_lib
)


add_executable(tests
        Test.cpp
)

target_link_libraries(tests
        todolist_lib
        gtest
        gtest_main
)

add_test(NAME ToDoListTests COMMAND tests)
