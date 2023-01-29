//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#ifndef UTIL_INTERVAL_H
#define UTIL_INTERVAL_H
#include <ArrayList.h>

struct interval{
    Array_list_ptr list;
};

typedef struct interval Interval;
typedef Interval* Interval_ptr;

Interval_ptr create_interval();
void free_interval(Interval_ptr interval);
void add_to_interval(Interval_ptr interval, int start, int end);
int get_first_of_interval(Interval_ptr interval, int index);
int get_last_of_interval(Interval_ptr interval, int index);
int size_of_interval(Interval_ptr interval);

#endif //UTIL_INTERVAL_H
