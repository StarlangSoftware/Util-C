//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#ifndef UTIL_PERMUTATION_H
#define UTIL_PERMUTATION_H

#include <stdbool.h>

struct permutation {
    int n;
    int *a;
};

typedef struct permutation Permutation;
typedef Permutation *Permutation_ptr;

Permutation_ptr create_permutation(int n);

void free_permutation(Permutation_ptr permutation);

bool next_permutation(Permutation_ptr permutation);

#endif //UTIL_PERMUTATION_H
