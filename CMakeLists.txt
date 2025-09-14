cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(tris VERSION 1.0)

set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

set(MENU_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/menu)
set(INPUT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/input)
set(GAME_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/game)
set(GAME_RULES_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/game_rules)

add_library(menu STATIC ${MENU_LIB_DIR}/menu.c)
add_library(input STATIC ${INPUT_LIB_DIR}/input.c)
add_library(game STATIC ${GAME_LIB_DIR}/game.c)
add_library(game_rules STATIC ${GAME_RULES_LIB_DIR}/game_rules.c)

add_executable(tris main.c)

target_link_libraries(tris PRIVATE
    menu
    input
    game
    game_rules)

set_target_properties(tris PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/release)

target_include_directories(tris PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(menu PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(input PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(game_rules PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)