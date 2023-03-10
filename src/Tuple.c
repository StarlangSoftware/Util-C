//
// Created by Olcay Taner YILDIZ on 16.01.2023.
//

#include <stdlib.h>
#include "Tuple.h"

/**
 * The constructor of {@link Tuple} struct which takes two integer inputs and initializes first and last variables
 * with given inputs.
 *
 * @param first integer input.
 * @param last  integer input.
 */
Tuple_ptr create_tuple(int first, int last) {
    Tuple_ptr result = malloc(sizeof(Tuple));
    result->first = first;
    result->last = last;
    return result;
}

void free_tuple(Tuple_ptr tuple) {
    free(tuple);
}
