//
// Created by Olcay Taner YILDIZ on 29.01.2023.
//

#include "../src/SubsetFromList.h"
#include "stdio.h"

void next1() {
    int *first_subset;
    int count;
    int list[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    Subset_from_list_ptr subset = create_subset_from_list(list, 10, 5);
    first_subset = subset->set;
    if (first_subset[0] != 10){
        printf("Test Failed in next1\n");
    }
    if (first_subset[1] != 20){
        printf("Test Failed in next1\n");
    }
    if (first_subset[2] != 30){
        printf("Test Failed in next1\n");
    }
    if (first_subset[3] != 40){
        printf("Test Failed in next1\n");
    }
    if (first_subset[4] != 50){
        printf("Test Failed in next1\n");
    }
    count = 1;
    while (next_subset_from_list(subset)) {
        count++;
    }
    if (count != 252){
        printf("Test Failed in next1\n");
    }
    free_subset_from_list(subset);
}

void next2() {
    int *first_subset;
    int count;
    int list[] = {9, 8, 2, 12, 7, 16, 17};
    Subset_from_list_ptr subset = create_subset_from_list(list, 7, 3);
    first_subset = subset->set;
    if (first_subset[0] != 9){
        printf("Test Failed in next2\n");
    }
    if (first_subset[1] != 8){
        printf("Test Failed in next2\n");
    }
    if (first_subset[2] != 2){
        printf("Test Failed in next2\n");
    }
    count = 1;
    while (next_subset_from_list(subset)) {
        count++;
    }
    if (count != 35){
        printf("Test Failed in next2\n");
    }
    free_subset_from_list(subset);
}

void next3() {
    int count = 0;
    int list[] = {9, 8, 2, 12, 7, 16, 17, 8, 3};
    for (int i = 0; i <= 9; i++){
        Subset_from_list_ptr subset = create_subset_from_list(list, 9, i);
        count++;
        while (next_subset_from_list(subset)) {
            count++;
        }
        free_subset_from_list(subset);
    }
    if (count != 512){
        printf("Test Failed in next3\n");
    }
}

int main(){
    next1();
    next2();
    next3();
}