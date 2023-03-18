cmake_minimum_required(VERSION 3.23)
project(Util C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(Util src/Tuple.c src/Tuple.h src/Swap.c src/Swap.h src/Interval.c src/Interval.h src/Permutation.c src/Permutation.h src/RandomArray.c src/RandomArray.h src/Subset.c src/Subset.h src/SubsetFromList.c src/SubsetFromList.h src/StringUtils.c src/StringUtils.h src/FileUtils.c src/FileUtils.h)
target_link_libraries(Util ${CONAN_LIBS})
