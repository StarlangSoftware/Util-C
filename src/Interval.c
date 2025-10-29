//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "Interval.h"
#include "Tuple.h"

Interval_ptr create_interval() {
    Interval_ptr result = malloc_(sizeof(Interval));
    result->list = create_array_list();
    return result;
}

void free_interval(Interval_ptr interval) {
    free_array_list(interval->list, (void (*)(void *)) free_tuple);
    free_(interval);
}

/**
 * The add method adds a new Tuple with given inputs to the list.
 *
 * @param interval Interval
 * @param start first element of Tuple.
 * @param end   second element of Tuple.
 */
void add_to_interval(Interval_ptr interval, int start, int end) {
    array_list_add(interval->list, create_tuple(start, end));
}

/**
 * The getFirst method returns the first element at the list vector's given index.
 *
 * @param interval Interval
 * @param index to use at getting tuple from vector.
 * @return the first element at the list vector's given index.
 */
int get_first_of_interval(const Interval* interval, int index) {
    return ((Tuple_ptr) array_list_get(interval->list, index))->first;
}

/**
 * The getLast method returns the last element at the list vector's given index.
 *
 * @param interval Interval
 * @param index to use at getting tuple from vector.
 * @return the last element at the list vector's given index.
 */
int get_last_of_interval(const Interval* interval, int index) {
    return ((Tuple_ptr) array_list_get(interval->list, index))->last;
}

/**
 * The size method returns the size of the list vector.
 *
 * @param interval Interval
 * @return size of the list vector.
 */
int size_of_interval(const Interval* interval) {
    return interval->list->size;
}
