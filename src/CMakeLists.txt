cmake_minimum_required(VERSION 3.23)
project(Util)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(data_structure_c)

add_library(Util Tuple.c Tuple.h Swap.c Swap.h Interval.c Interval.h Permutation.c Permutation.h RandomArray.c RandomArray.h Subset.c Subset.h SubsetFromList.c SubsetFromList.h StringUtils.c StringUtils.h FileUtils.c FileUtils.h Pair.c Pair.h)
target_link_libraries(Util data_structure_c::data_structure_c)
