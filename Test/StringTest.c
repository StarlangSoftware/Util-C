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

int main(){
    test_uppercase();
    test_lowercase();
}