//
// Created by Olcay Taner YILDIZ on 28.01.2023.
//
#include <stdlib.h>
#include <HashMap/HashMap.h>
#include <Memory/Memory.h>

#include "../src/RandomArray.h"
#include "stdio.h"

void normalizedArrayTest() {
    double *array;
    array = normalized_array(10);
    double sum = 0.0;
    for (int i = 0; i < 10; i++) {
        sum += array[i];
    }
    if (sum <= 0.99999999) {
        printf("Test Failed in normalizedArrayTest\n");
    }
    free(array);
}

void indexArrayTest() {
    Array_list_ptr array;
    array = index_array(10, 0);
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += *((int *) array_list_get(array, i));
    }
    if (sum != 45) {
        printf("Test Failed in indexArrayTest\n");
    }
    free_array_list(array, (void (*)(void *)) free_int);
}

int main() {
    start_memory_check();
    normalizedArrayTest();
    indexArrayTest();
    end_memory_check();
}