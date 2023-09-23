//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#ifndef UTIL_STRINGUTILS_H
#define UTIL_STRINGUTILS_H

#include <ArrayList.h>

struct string {
    char *s;
    int max_size;
};

typedef struct string String;
typedef String *String_ptr;

String_ptr create_string();

String_ptr create_string2(const char *s);

String_ptr create_string3(const char* s1, const char* s2);

String_ptr create_string4(const char* s1, const char* s2, const char* s3);

void free_string_ptr(String_ptr string);

void clean_string(String_ptr string);

void string_append(String_ptr string, const char *src);

void string_append_s(String_ptr string, const String* src);

void string_append_char(String_ptr string, char ch);

char *string_copy(const String* string);

bool string_contains(const String* large, const String* small);

bool string_contains2(const String* large, const char* small);

char *str_copy(char *dst, const char *src);

char *str_concat(const char *src1, const char *src2);

bool str_contains(const char *large, const char *small);

bool str_contains_c(const char *s, char ch);

bool string_equals(const String* s1, const String* s2);

bool string_equals2(const String* s1, const char* s2);

bool string_empty(const String* s);

Array_list_ptr str_split(const char *s, char ch);

char *uppercase_en(const char *src);

char *lowercase_en(const char *src);

char* left_trim(char* s);

#endif //UTIL_STRINGUTILS_H
