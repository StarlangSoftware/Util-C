//
// Created by Olcay Taner YILDIZ on 29.01.2023.
//

#include "stdio.h"
#include "../src/Subset.h"

void next1() {
    int *first_subset;
    int count;
    Subset_ptr subset = create_subset(1, 10, 5);
    first_subset = subset->set;
    if (first_subset[0] != 1) {
        printf("Test Failed in next1\n");
    }
    if (first_subset[1] != 2) {
        printf("Test Failed in next1\n");
    }
    if (first_subset[2] != 3) {
        printf("Test Failed in next1\n");
    }
    if (first_subset[3] != 4) {
        printf("Test Failed in next1\n");
    }
    if (first_subset[4] != 5) {
        printf("Test Failed in next1\n");
    }
    count = 1;
    while (next_subset(subset)) {
        count++;
    }
    if (count != 252) {
        printf("Test Failed in next1\n");
    }
    free_subset(subset);
}

void next2() {
    int *first_subset;
    int count;
    Subset_ptr subset = create_subset(1, 20, 3);
    first_subset = subset->set;
    if (first_subset[0] != 1) {
        printf("Test Failed in next2\n");
    }
    if (first_subset[1] != 2) {
        printf("Test Failed in next2\n");
    }
    if (first_subset[2] != 3) {
        printf("Test Failed in next2\n");
    }
    count = 1;
    while (next_subset(subset)) {
        count++;
    }
    if (count != 1140) {
        printf("Test Failed in next2\n");
    }
    free_subset(subset);
}

void next3() {
    int count = 0;
    for (int i = 0; i <= 10; i++) {
        Subset_ptr subset = create_subset(1, 10, i);
        count++;
        while (next_subset(subset)) {
            count++;
        }
        free_subset(subset);
    }
    if (count != 1024) {
        printf("Test Failed in next3\n");
    }
}

int main(){
    next1();
    next2();
    next3();
}