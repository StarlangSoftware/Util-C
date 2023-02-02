//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <stdlib.h>
#include <string.h>
#include "StringUtils.h"

char *str_copy(char *dst, const char *src) {
    dst = malloc(strlen(src) + 1);
    strcpy(dst, src);
    return dst;
}

Array_list_ptr str_split(char *s, char ch) {
    char *substring;
    Array_list_ptr result = create_array_list();
    char* buffer = malloc(strlen(s) + 1);
    int j = 0;
    while (*s){
        if (*s != ch){
            buffer[j] = *s;
            j++;
        } else {
            buffer[j] = '\0';
            if (j != 0){
                substring = str_copy(substring, buffer);
                array_list_add(result, substring);
            }
            j = 0;
        }
        s++;
    }
    buffer[j] = '\0';
    if (j != 0){
        substring = str_copy(substring, buffer);
        array_list_add(result, substring);
    }
    return result;
}
