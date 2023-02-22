//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/StringUtils.h"

void test_uppercase(){
    char* upper = uppercase_en("abcdefghijklmnopqrstuvwxyz");
    if (strcmp(upper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != 0){
        printf("Test Failed in test_uppercase\n");
    }
    free(upper);
}

void test_lowercase(){
    char* upper = lowercase_en("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (strcmp(upper, "abcdefghijklmnopqrstuvwxyz") != 0){
        printf("Test Failed in test_lowercase\n");
    }
    free(upper);
}

void test_concat(){
    char* result = str_concat("ali", "veli");
    if (strcmp(result, "aliveli") != 0){
        printf("Test Failed in test_lowercase\n");
    }
}

void test_string(){
    String_ptr s = create_string();
    string_append(s, "aliveli");
    printf("%s\n", s->s);
    string_append(s, "aliveli");
    printf("%s\n", s->s);
    string_append(s, "aliveli");
    printf("%s\n", s->s);
    string_append_char(s, 'a');
    printf("%s\n", s->s);
    free_string(s);
}

int main(){
    test_uppercase();
    test_lowercase();
    test_concat();
    test_string();
}