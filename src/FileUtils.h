//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#ifndef UTIL_FILEUTILS_H
#define UTIL_FILEUTILS_H

#include <ArrayList.h>
#include <stdio.h>
#include <HashMap/HashSet.h>

#define MAX_LINE_LENGTH 16384

Array_list_ptr read_items(FILE* input_file, char delimiter);

Array_list_ptr read_lines(const char* file_name);

Hash_set_ptr read_hash_set(const char *file_name);

#endif //UTIL_FILEUTILS_H
