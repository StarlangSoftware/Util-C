//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#ifndef UTIL_SUBSET_H
#define UTIL_SUBSET_H

#include <stdbool.h>

struct subset {
    int *set;
    int element_count;
    int range_end;
};

typedef struct subset Subset;
typedef Subset *Subset_ptr;

Subset_ptr create_subset(int range_start, int range_end, int element_count);

void free_subset(Subset_ptr subset);

bool next_subset(Subset_ptr subset);

#endif //UTIL_SUBSET_H
