cmake_minimum_required(VERSION 3.20)
project(MCSL-Lib)

set(CMAKE_C_STANDARD 11)

add_library(MCSL_LIB MCSL.c Parser.c Lexer.c Token.c utils/List.c)
