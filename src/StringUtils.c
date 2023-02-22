//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

char *uppercase_en(char *src) {
    char* result = malloc(strlen(src) + 1);
    char* t = result;
    while (*src){
        *result = toupper(*src);
        result++;
        src++;
    }
    *result = '\0';
    return t;
}

char *lowercase_en(char *src) {
    char* result = malloc(strlen(src) + 1);
    char* t = result;
    while (*src){
        *result = tolower(*src);
        result++;
        src++;
    }
    *result = '\0';
    return t;
}

char *str_concat(char *src1, char *src2) {
    char* result = malloc(strlen(src1) + strlen(src2) + 1);
    result = strcpy(result, src1);
    result = strcat(result, src2);
    return result;
}

String_ptr create_string() {
    String_ptr result = malloc(sizeof(String));
    result->s = calloc(5, sizeof(char));
    result->max_size = 5;
    return result;
}

void free_string(String_ptr string) {
    free(string->s);
    free(string);
}

void string_append(String_ptr string, char *src) {
    while (strlen(string->s) + strlen(src) >= string->max_size){
        string->max_size *= 2;
        string->s = realloc(string->s, string->max_size * sizeof(char));
    }
    strcat(string->s, src);
}

char *string_copy(String_ptr string) {
    char* result = NULL;
    return str_copy(result, string->s);
}

void string_append_char(String_ptr string, char ch) {
    int length;
    if (strlen(string->s) + 1 >= string->max_size){
        string->max_size *= 2;
        string->s = realloc(string->s, string->max_size * sizeof(char));
    }
    length = strlen(string->s);
    string->s[length] = ch;
    string->s[length + 1] = '\0';
}

String_ptr create_string2(char *s) {
    String_ptr result = create_string();
    string_append(result, s);
    return  result;
}
