cmake_minimum_required(VERSION 3.24)

project("Farming Simulator")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

enable_testing()
include(Catch)

add_executable(farm_printer_test tests/farm_printer_test.cpp src/farm_printer.cpp src/farm.cpp src/soil.cpp src/player.cpp src/plot.cpp src/bunny.cpp)
add_executable(farm_test tests/farm_test.cpp src/farm.cpp src/soil.cpp src/carrot.cpp src/lettuce.cpp src/beet.cpp src/spinach.cpp src/brussel_sprout.cpp src/player.cpp src/plot.cpp src/bunny.cpp)
add_executable(soil_test tests/soil_test.cpp src/soil.cpp src/plot.cpp)
add_executable(carrot_test tests/carrot_test.cpp src/carrot.cpp src/plot.cpp)
add_executable(lettuce_test tests/lettuce_test.cpp src/lettuce.cpp src/plot.cpp)
add_executable(beet_test tests/beet_test.cpp src/beet.cpp src/plot.cpp)
add_executable(spinach_test tests/spinach_test.cpp src/spinach.cpp src/plot.cpp)
add_executable(brussel_sprout_test tests/brussel_sprout_test.cpp src/brussel_sprout.cpp src/plot.cpp)
add_executable(player_test tests/player_test.cpp src/player.cpp src/plot.cpp)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(main main.cpp ${SRC_FILES})

target_link_libraries(farm_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(farm_printer_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(soil_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(carrot_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(lettuce_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(beet_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(spinach_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(brussel_sprout_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(player_test PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(farm_printer_test)
catch_discover_tests(farm_test)
catch_discover_tests(soil_test)
catch_discover_tests(carrot_test)
catch_discover_tests(lettuce_test)
catch_discover_tests(beet_test)
catch_discover_tests(spinach_test)
catch_discover_tests(brussel_sprout_test)
catch_discover_tests(player_test)
