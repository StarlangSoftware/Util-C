//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#ifndef UTIL_STRINGUTILS_H
#define UTIL_STRINGUTILS_H

#include <ArrayList.h>

char* str_copy(char* dst, const char* src);
Array_list_ptr str_split(char* s, char ch);

#endif //UTIL_STRINGUTILS_H
