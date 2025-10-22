cmake_minimum_required(VERSION 3.24)
project(Conto_Corrente)

set(CMAKE_CXX_STANDARD 17)

add_executable(Conto_Corrente main.cpp Transazione.h Transazione.cpp)
