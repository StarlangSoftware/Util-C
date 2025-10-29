//
// Created by Olcay Taner YILDIZ on 28.01.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "SubsetFromList.h"

/**
 * A constructor of SubsetFromList class takes an integer list and an integer elementCount as inputs. It initializes
 * elementList and elementCount variables with given inputs, then creates 3 arrays; set, indexList, and multiset with the
 * size of given elementCount and multisetCount, which is derived from elementCount, respectively. Then, it assigns
 * i to each ith element of indexList array and use this index to point at elementList and
 * assigns to set array.
 *
 * @param list         array type input.
 * @param list_size         size of thw array type input.
 * @param element_count integer input element count.
 */
Subset_from_list_ptr create_subset_from_list(int *list, int list_size, int element_count) {
    Subset_from_list_ptr result = malloc_(sizeof(Subset_from_list));
    result->element_list = list;
    result->element_count = element_count;
    result->list_size = list_size;
    result->set = malloc_(element_count * sizeof(int));
    result->index_list = malloc_(element_count * sizeof(int));
    for (int i = 0; i < element_count; i++) {
        result->index_list[i] = i;
        result->set[i] = result->element_list[result->index_list[i]];
    }
    return result;
}

void free_subset_from_list(Subset_from_list_ptr subset) {
    free_(subset->set);
    free_(subset->index_list);
    free_(subset);
}

/**
 * The next method generates the next subset from list.
 *
 * @return true if next subset generation from list is possible, false otherwise.
 */
bool next_subset_from_list(Subset_from_list_ptr subset) {
    int i, j;
    for (i = subset->element_count - 1; i > -1; i--) {
        subset->index_list[i]++;
        if (subset->index_list[i] < subset->list_size - subset->element_count + i + 1) {
            break;
        }
    }
    if (i == -1) {
        return false;
    }
    subset->set[i] = subset->element_list[subset->index_list[i]];
    for (j = i + 1; j < subset->element_count; j++) {
        subset->index_list[j] = subset->index_list[j - 1] + 1;
        subset->set[j] = subset->element_list[subset->index_list[j]];
    }
    return true;
}
