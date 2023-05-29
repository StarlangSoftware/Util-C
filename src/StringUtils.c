//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "StringUtils.h"

char *str_copy(char *dst, const char *src) {
    dst = malloc(strlen(src) + 1);
    strcpy(dst, src);
    return dst;
}

Array_list_ptr str_split(const char *s, char ch) {
    char *substring;
    Array_list_ptr result = create_array_list();
    char *buffer = malloc(strlen(s) + 1);
    int j = 0;
    while (*s) {
        if (*s != ch) {
            buffer[j] = *s;
            j++;
        } else {
            buffer[j] = '\0';
            if (j != 0) {
                substring = str_copy(substring, buffer);
                array_list_add(result, substring);
            }
            j = 0;
        }
        s++;
    }
    buffer[j] = '\0';
    if (j != 0) {
        substring = str_copy(substring, buffer);
        array_list_add(result, substring);
    }
    return result;
}

char *uppercase_en(const char *src) {
    char *result = malloc(strlen(src) + 1);
    char *t = result;
    while (*src) {
        *result = toupper(*src);
        result++;
        src++;
    }
    *result = '\0';
    return t;
}

char *lowercase_en(const char *src) {
    char *result = malloc(strlen(src) + 1);
    char *t = result;
    while (*src) {
        *result = tolower(*src);
        result++;
        src++;
    }
    *result = '\0';
    return t;
}

char *str_concat(const char *src1, const char *src2) {
    char *result = malloc(strlen(src1) + strlen(src2) + 1);
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

void free_string_ptr(String_ptr string) {
    free(string->s);
    free(string);
}

void string_append(String_ptr string, const char *src) {
    while (strlen(string->s) + strlen(src) >= string->max_size) {
        string->max_size *= 2;
        string->s = realloc(string->s, string->max_size * sizeof(char));
    }
    strcat(string->s, src);
}

char *string_copy(const String* string) {
    char *result = NULL;
    return str_copy(result, string->s);
}

void string_append_char(String_ptr string, char ch) {
    unsigned long length;
    if (strlen(string->s) + 1 >= string->max_size) {
        string->max_size *= 2;
        string->s = realloc(string->s, string->max_size * sizeof(char));
    }
    length = strlen(string->s);
    string->s[length] = ch;
    string->s[length + 1] = '\0';
}

String_ptr create_string2(const char *s) {
    String_ptr result = create_string();
    string_append(result, s);
    return result;
}

String_ptr create_string3(const char *s1, const char *s2) {
    String_ptr result = create_string2(s1);
    string_append(result, s2);
    return result;
}

String_ptr create_string4(const char *s1, const char *s2, const char *s3) {
    String_ptr result = create_string3(s1, s2);
    string_append(result, s3);
    return result;
}

void clean_string(String_ptr string) {
    free(string->s);
    string->s = calloc(5, sizeof(char));
    string->max_size = 5;
}

void string_append_s(String_ptr string, const String* src) {
    while (strlen(string->s) + strlen(src->s) >= string->max_size) {
        string->max_size *= 2;
        string->s = realloc(string->s, string->max_size * sizeof(char));
    }
    strcat(string->s, src->s);
}

bool string_contains(String_ptr large, String_ptr small) {
    return strstr(large->s, small->s) != NULL;
}

bool string_contains2(String_ptr large, const char *small) {
    return strstr(large->s, small) != NULL;
}

/**
 * The contains method takes a String and a char input then check the given String contains the given char.
 *
 * @param s         String input to search for the char.
 * @param st Char input to look for in String.
 * @return true if char is found, false otherwise.
 */
bool str_contains(const char *large, const char *small) {
    return strstr(large, small) != NULL;
}

/**
 * The contains method takes a String and a char input then check the given String contains the given char.
 *
 * @param s         String input to search for the char.
 * @param ch Char input to look for in String.
 * @return true if char is found, false otherwise.
 */
bool str_contains_c(const char *s, char ch) {
    return strstr(s, &ch) != NULL;
}
