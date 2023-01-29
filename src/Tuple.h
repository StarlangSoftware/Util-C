//
// Created by Olcay Taner YILDIZ on 16.01.2023.
//

#ifndef UTIL_TUPLE_H
#define UTIL_TUPLE_H

struct tuple{
    int first;
    int last;
};

typedef struct tuple Tuple;
typedef Tuple* Tuple_ptr;

Tuple_ptr create_tuple(int first, int last);
void free_tuple(Tuple_ptr tuple);

#endif //UTIL_TUPLE_H
