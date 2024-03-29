//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Memory/Memory.h>
#include "StringUtils.h"

char *str_copy(char *dst, const char *src) {
    if (src == NULL){
        return NULL;
    }
    dst = malloc_(strlen(src) + 1, "str_copy");
    strcpy(dst, src);
    return dst;
}

Array_list_ptr str_split(const char *s, char ch) {
    char separator[2];
    separator[0] = ch;
    separator[1] = '\0';
    return str_split2(s, separator);
}

Array_list_ptr str_split2(const char *s, const char *word) {
    char *substring;
    Array_list_ptr result = create_array_list();
    char *buffer = malloc_(strlen(s) + 1, "str_split2");
    int j = 0;
    while (*s) {
        if (*s != word[0]) {
            buffer[j] = *s;
            j++;
        } else {
            bool found = true;
            for (int i = 1; i < strlen(word); i++){
                if (*(s + i) != word[i]){
                    found = false;
                    break;
                }
            }
            if (found){
                buffer[j] = '\0';
                if (j != 0) {
                    substring = str_copy(substring, buffer);
                    array_list_add(result, substring);
                }
                j = 0;
                s += strlen(word) - 1;
            } else {
                buffer[j] = *s;
                j++;
            }
        }
        s++;
    }
    buffer[j] = '\0';
    if (j != 0) {
        substring = str_copy(substring, buffer);
        array_list_add(result, substring);
    }
    free_(buffer);
    return result;
}

char *uppercase_en(const char *src) {
    if (src == NULL){
        return NULL;
    }
    char *result = malloc_(strlen(src) + 1, "uppercase_en");
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
    if (src == NULL){
        return NULL;
    }
    char *result = malloc_(strlen(src) + 1, "lowercase_en");
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
    char *result = malloc_(strlen(src1) + strlen(src2) + 1, "str_concat");
    result = strcpy(result, src1);
    result = strcat(result, src2);
    return result;
}

String_ptr create_string() {
    String_ptr result = malloc_(sizeof(String), "create_string_1");
    result->s = calloc_(5, sizeof(char), "create_string_2");
    result->max_size = 5;
    return result;
}

void free_string_ptr(String_ptr string) {
    free_(string->s);
    free_(string);
}

void string_append(String_ptr string, const char *src) {
    while (strlen(string->s) + strlen(src) >= string->max_size) {
        string->max_size *= 2;
        string->s = realloc_(string->s, string->max_size * sizeof(char), "string_append");
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
        string->s = realloc_(string->s, string->max_size * sizeof(char), "string_append_char");
    }
    length = strlen(string->s);
    string->s[length] = ch;
    string->s[length + 1] = '\0';
}

String_ptr create_string2(const char *s) {
    String_ptr result = malloc_(sizeof(String), "create_string2_1");
    result->s = calloc_(5, sizeof(char), "create_string2_2");
    result->max_size = 5;
    string_append(result, s);
    return result;
}

String_ptr create_string3(const char *s1, const char *s2) {
    String_ptr result = malloc_(sizeof(String), "create_string3_1");
    result->s = calloc_(5, sizeof(char), "create_string3_2");
    result->max_size = 5;
    string_append(result, s1);
    string_append(result, s2);
    return result;
}

String_ptr create_string4(const char *s1, const char *s2, const char *s3) {
    String_ptr result = malloc_(sizeof(String), "create_string4_1");
    result->s = calloc_(5, sizeof(char), "create_string4_2");
    result->max_size = 5;
    string_append(result, s1);
    string_append(result, s2);
    string_append(result, s3);
    return result;
}

void clean_string(String_ptr string) {
    free_(string->s);
    string->s = calloc_(5, sizeof(char), "clean_string");
    string->max_size = 5;
}

void string_append_s(String_ptr string, const String* src) {
    while (strlen(string->s) + strlen(src->s) >= string->max_size) {
        string->max_size *= 2;
        string->s = realloc_(string->s, string->max_size * sizeof(char), "string_append_s");
    }
    strcat(string->s, src->s);
}

bool string_contains(const String* large, const String* small) {
    return strstr(large->s, small->s) != NULL;
}

bool string_contains2(const String* large, const char *small) {
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

bool string_equals(const String* s1, const String* s2) {
    return strcmp(s1->s, s2->s) == 0;
}

bool string_equals2(const String* s1, const char *s2) {
    return strcmp(s1->s, s2) == 0;
}

bool string_empty(const String *s) {
    return strlen(s->s) == 0;
}

char *left_trim(char *s) {
    int i = 0;
    while (isspace(s[i])){
        i++;
    }
    return &(s[i]);
}

bool string_in_list(const char *s, char **list, int size) {
    for (int i = 0; i < size; i++){
        if (strcmp(s, list[i]) == 0){
            return true;
        }
    }
    return false;
}

void string_replace(String_ptr st, const char *word) {
    clean_string(st);
    string_append(st, word);
}

int string_index(const char *s, char *list[], int size) {
    for (int i = 0; i < size; i++){
        if (strcmp(s, list[i]) == 0){
            return i;
        }
    }
    return -1;
}

Array_list_ptr str_split3(const char *s, const char *separator_list) {
    char *substring;
    Array_list_ptr result = create_array_list();
    char *buffer = malloc_(strlen(s) + 1, "str_split3");
    int j = 0;
    while (*s) {
        bool found = false;
        for (int i = 0; i < strlen(separator_list); i++){
            if (*s == separator_list[i]){
                found = true;
                break;
            }
        }
        if (!found) {
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
    free_(buffer);
    return result;
}

char *clone_string(const char *s) {
    char* result = malloc_(strlen(s) + 1, "clone_string");
    strcpy(result, s);
    return result;
}
