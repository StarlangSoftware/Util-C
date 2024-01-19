cmake_minimum_required(VERSION 3.23)
project(Util)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(data_structure_c REQUIRED)

add_library(Util src/Tuple.c src/Tuple.h src/Swap.c src/Swap.h src/Interval.c src/Interval.h src/Permutation.c src/Permutation.h src/RandomArray.c src/RandomArray.h src/Subset.c src/Subset.h src/SubsetFromList.c src/SubsetFromList.h src/StringUtils.c src/StringUtils.h src/FileUtils.c src/FileUtils.h
        src/Pair.c
        src/Pair.h)
target_link_libraries(Util data_structure_c::data_structure_c)
add_executable(PermutationTest src/Tuple.c src/Tuple.h src/Swap.c src/Swap.h src/Interval.c src/Interval.h src/Permutation.c src/Permutation.h src/RandomArray.c src/RandomArray.h src/Subset.c src/Subset.h src/SubsetFromList.c src/SubsetFromList.h src/StringUtils.c src/StringUtils.h src/FileUtils.c src/FileUtils.h Test/PermutationTest.c)
target_link_libraries(PermutationTest data_structure_c::data_structure_c)
add_executable(RandomNormalizedArrayTest src/Tuple.c src/Tuple.h src/Swap.c src/Swap.h src/Interval.c src/Interval.h src/Permutation.c src/Permutation.h src/RandomArray.c src/RandomArray.h src/Subset.c src/Subset.h src/SubsetFromList.c src/SubsetFromList.h src/StringUtils.c src/StringUtils.h src/FileUtils.c src/FileUtils.h Test/RandomNormalizedArrayTest.c)
target_link_libraries(RandomNormalizedArrayTest data_structure_c::data_structure_c)
add_executable(SubsetTest src/Tuple.c src/Tuple.h src/Swap.c src/Swap.h src/Interval.c src/Interval.h src/Permutation.c src/Permutation.h src/RandomArray.c src/RandomArray.h src/Subset.c src/Subset.h src/SubsetFromList.c src/SubsetFromList.h src/StringUtils.c src/StringUtils.h src/FileUtils.c src/FileUtils.h Test/SubsetTest.c)
target_link_libraries(SubsetTest data_structure_c::data_structure_c)
add_executable(SubsetFromListTest src/Tuple.c src/Tuple.h src/Swap.c src/Swap.h src/Interval.c src/Interval.h src/Permutation.c src/Permutation.h src/RandomArray.c src/RandomArray.h src/Subset.c src/Subset.h src/SubsetFromList.c src/SubsetFromList.h src/StringUtils.c src/StringUtils.h src/FileUtils.c src/FileUtils.h Test/SubsetFromListTest.c)
target_link_libraries(SubsetFromListTest data_structure_c::data_structure_c)
add_executable(StringTest src/Tuple.c src/Tuple.h src/Swap.c src/Swap.h src/Interval.c src/Interval.h src/Permutation.c src/Permutation.h src/RandomArray.c src/RandomArray.h src/Subset.c src/Subset.h src/SubsetFromList.c src/SubsetFromList.h src/StringUtils.c src/StringUtils.h src/FileUtils.c src/FileUtils.h Test/StringTest.c)
target_link_libraries(StringTest data_structure_c::data_structure_c)
