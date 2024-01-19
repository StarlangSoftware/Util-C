//
// Created by Olcay Taner YILDIZ on 19.01.2024.
//

#ifndef UTIL_PAIR_H
#define UTIL_PAIR_H

struct pair{
    char* first;
    char* second;
};

typedef struct pair Pair;

typedef Pair *Pair_ptr;

Pair_ptr create_pair(char* first, char* second);

void free_pair(Pair_ptr pair);

#endif //UTIL_PAIR_H
