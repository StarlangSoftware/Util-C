//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#include <stdlib.h>
#include "Permutation.h"
#include "Swap.h"
#include "Memory/Memory.h"

/**
 * A constructor of Permutation class which creates a new array and assigns integer
 * numbers starting from 0 to given input n.
 *
 * @param n integer input.
 */
Permutation_ptr create_permutation(int n) {
    Permutation_ptr result = malloc_(sizeof(Permutation), "create_permutation_1");
    int i;
    result->n = n;
    result->a = malloc_(n * sizeof(int), "create_permutation_2");
    for (i = 0; i < n; i++) {
        result->a[i] = i;
    }
    return result;
}

void free_permutation(Permutation_ptr permutation) {
    free_(permutation->a);
    free_(permutation);
}

/**
 * The next method generates next permutation for the array a.
 *
 * @param permutation Permutation
 * @return true if next permutation is possible, false otherwise.
 */
bool next_permutation(Permutation_ptr permutation) {
    int i = permutation->n - 2;
    int j, k;
    while (i >= 0 && permutation->a[i] >= permutation->a[i + 1]) {
        i--;
    }
    if (i == -1) {
        return false;
    }
    j = permutation->n - 1;
    while (permutation->a[i] >= permutation->a[j]) {
        j--;
    }
    swap_int(permutation->a, i, j);
    k = i + 1;
    j = permutation->n - 1;
    while (k < j) {
        swap_int(permutation->a, j, k);
        k++;
        j--;
    }
    return true;
}
