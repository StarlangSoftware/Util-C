//
// Created by Olcay Taner YILDIZ on 28.01.2023.
//
#include "../src/Permutation.h"
#include "stdio.h"

void next1() {
    int *firstPermutation;
    int count;
    Permutation_ptr permutation = create_permutation(3);
    firstPermutation = permutation->a;
    if (firstPermutation[0] != 0){
        printf("Test Failed in next1\n");
    }
    if (firstPermutation[1] != 1){
        printf("Test Failed in next1\n");
    }
    if (firstPermutation[2] != 2){
        printf("Test Failed in next1\n");
    }
    count = 1;
    while (next_permutation(permutation)) {
        count++;
    }
    if (count != 6){
        printf("Test Failed in next1\n");
    }
    free_permutation(permutation);
}

void next2() {
    int *firstPermutation;
    int count;
    Permutation_ptr permutation = create_permutation(5);
    firstPermutation = permutation->a;
    if (firstPermutation[0] != 0){
        printf("Test Failed in next2\n");
    }
    if (firstPermutation[1] != 1){
        printf("Test Failed in next2\n");
    }
    if (firstPermutation[2] != 2){
        printf("Test Failed in next2\n");
    }
    if (firstPermutation[3] != 3){
        printf("Test Failed in next2\n");
    }
    if (firstPermutation[4] != 4){
        printf("Test Failed in next2\n");
    }
    count = 1;
    while (next_permutation(permutation)) {
        count++;
    }
    if (count != 120){
        printf("Test Failed in next2\n");
    }
    free_permutation(permutation);
}

int main() {
    next1();
    next2();
}