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

String_ptr create_string2(char *s);

void free_string_ptr(String_ptr string);

void clean_string(String_ptr string);

void string_append(String_ptr string, char *src);

void string_append_s(String_ptr string, String_ptr src);

void string_append_char(String_ptr string, char ch);

char *string_copy(const String* string);

char *str_copy(char *dst, const char *src);

char *str_concat(const char *src1, const char *src2);

Array_list_ptr str_split(const char *s, char ch);

char *uppercase_en(const char *src);

char *lowercase_en(const char *src);

#endif //UTIL_STRINGUTILS_H
