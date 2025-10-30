cmake_minimum_required(VERSION 3.24)
project(Conto_Corrente)

set(CMAKE_CXX_STANDARD 17)


add_library(Engine
        src/Transazione.cpp
        src/ContoCorrente.cpp)

target_include_directories(Engine PUBLIC include)


add_executable(App src/main.cpp test/TestContoCorrente.cpp test/TestContoCorrente.cpp test/TestContoCorrente.cpp)


add_executable(Conto_Corrente src/main.cpp src/Transazione.cpp src/ContoCorrente.cpp)


target_link_libraries(App PRIVATE Engine)



enable_testing()
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)


add_executable(runTests
        test/TestContoCorrente.cpp)

target_link_libraries(runTests PRIVATE Engine gtest_main)


include(GoogleTest)
gtest_discover_tests(runTests)