//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <string.h>
#include <stdio.h>
#include <Memory/Memory.h>
#include "../src/StringUtils.h"

void test_uppercase() {
    char *upper = uppercase_en("abcdefghijklmnopqrstuvwxyz");
    if (strcmp(upper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != 0) {
        printf("Test Failed in test_uppercase\n");
    }
    free_(upper);
}

void test_lowercase() {
    char *upper = lowercase_en("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (strcmp(upper, "abcdefghijklmnopqrstuvwxyz") != 0) {
        printf("Test Failed in test_lowercase\n");
    }
    free_(upper);
}

void test_concat() {
    char *result = str_concat("ali", "veli");
    if (strcmp(result, "aliveli") != 0) {
        printf("Test Failed in test_lowercase\n");
    }
    free_(result);
}

void test_string() {
    String_ptr s = create_string();
    string_append(s, "aliveli");
    printf("%s\n", s->s);
    string_append(s, "aliveli");
    printf("%s\n", s->s);
    string_append(s, "aliveli");
    printf("%s\n", s->s);
    string_append_char(s, 'a');
    printf("%s\n", s->s);
    free_string_ptr(s);
}

void test_split1(){
    Array_list_ptr items = str_split("4|1|SENTENCE", '|');
    for (int i = 0; i < items->size; i++){
        printf("%s\n", (char*) array_list_get(items, i));
    }
    free_array_list(items, free_);
}

void test_split2(){
    Array_list_ptr items = str_split2("iyi+ADJ^DB+VERB+BECOME^DB+VERB+CAUS^DB+VERB+PASS+POS^DB+VERB+ABLE^DB+NOUN+INF2+A3PL+P3PL+ABL", "^DB+");
    for (int i = 0; i < items->size; i++){
        printf("%s\n", (char*) array_list_get(items, i));
    }
    free_array_list(items, free_);
    items = str_split2("serbest+ADJ", "^DB+");
    for (int i = 0; i < items->size; i++){
        printf("%s\n", (char*) array_list_get(items, i));
    }
    free_array_list(items, free_);
}

void test_split3(){
    Array_list_ptr items = str_split3("[4,1,(SENTENCE)]", ",[]()");
    for (int i = 0; i < items->size; i++){
        printf("%s\n", (char*) array_list_get(items, i));
    }
    free_array_list(items, free_);
}

int main() {
    test_uppercase();
    test_lowercase();
    test_concat();
    test_string();
    test_split1();
    test_split2();
    test_split3();
}