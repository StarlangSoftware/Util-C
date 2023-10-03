//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#include <stdlib.h>
#include "Subset.h"

/**
 * The constructor of Subset class which takes 3 integer inputs; rangeStart, rangeEnd, and elementCount.
 * It initializes variables rangeEnd and elementCount with given inputs, creates 2 arrays; set and multiset with the
 * size of given elementCount and multisetCount, which is derived from elementCount, respectively. Then, it assigns
 * rangeStart+i to each ith element of set array.
 *
 * @param range_start   integer input defining start range.
 * @param range_end     integer input defining ending range.
 * @param element_count integer input element count.
 */
Subset_ptr create_subset(int range_start, int range_end, int element_count) {
    Subset_ptr result = malloc(sizeof(Subset));
    result->range_end = range_end;
    result->element_count = element_count;
    result->set = malloc(element_count * sizeof(int));
    for (int i = 0; i < element_count; i++) {
        result->set[i] = range_start + i;
    }
    return result;
}

void free_subset(Subset_ptr subset) {
    free(subset->set);
    free(subset);
}

/**
 * The next method generates the next subset.
 *
 * @return true if next subset generation is possible, false otherwise.
 */
bool next_subset(Subset_ptr subset) {
    int i, j;
    for (i = subset->element_count - 1; i > -1; i--) {
        subset->set[i]++;
        if (subset->set[i] <= subset->range_end - subset->element_count + i + 1) {
            break;
        }
    }
    if (i == -1) {
        return false;
    }
    for (j = i + 1; j < subset->element_count; j++) {
        subset->set[j] = subset->set[j - 1] + 1;
    }
    return true;
}
