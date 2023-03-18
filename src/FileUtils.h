//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#ifndef UTIL_FILEUTILS_H
#define UTIL_FILEUTILS_H

#include <ArrayList.h>
#include <stdio.h>

Array_list_ptr read_items(FILE* input_file, char delimiter);

#endif //UTIL_FILEUTILS_H
