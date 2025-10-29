//
// Created by Olcay Taner YILDIZ on 19.01.2024.
//

#include <Memory/Memory.h>
#include "Pair.h"
#include "StringUtils.h"

Pair_ptr create_pair(char *first, char *second) {
    Pair_ptr result = malloc_(sizeof(Pair));
    result->first = str_copy(result->first, first);
    result->second = str_copy(result->second, second);
    return result;
}

void free_pair(Pair_ptr pair) {
    free_(pair->first);
    free_(pair->second);
    free_(pair);
}
