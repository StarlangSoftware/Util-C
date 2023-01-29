//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#include <stdlib.h>
#include "Interval.h"
#include "Tuple.h"

Interval_ptr create_interval() {
    Interval_ptr result = malloc(sizeof(Interval));
    result->list = create_array_list();
    return result;
}

void free_interval(Interval_ptr interval) {
    free_array_list(interval->list, (void (*)(void *)) free_tuple);
    free(interval);
}

/**
 * The add method adds a new {@link Tuple} with given inputs to the list.
 *
 * @param interval Interval
 * @param start first element of {@link Tuple}.
 * @param end   second element of {@link Tuple}.
 */
void add_to_interval(Interval_ptr interval, int start, int end) {
    array_list_add(interval->list, create_tuple(start, end));
}

/**
 * The getFirst method returns the first element at the list {@link vector}'s given index.
 *
 * @param interval Interval
 * @param index to use at getting tuple from {@link vector}.
 * @return the first element at the list {@link vector}'s given index.
 */
int get_first_of_interval(Interval_ptr interval, int index) {
    return ((Tuple_ptr) array_list_get(interval->list, index))->first;
}

/**
 * The getLast method returns the last element at the list {@link vector}'s given index.
 *
 * @param interval Interval
 * @param index to use at getting tuple from {@link vector}.
 * @return the last element at the list {@link vector}'s given index.
 */
int get_last_of_interval(Interval_ptr interval, int index) {
    return ((Tuple_ptr) array_list_get(interval->list, index))->last;
}

/**
 * The size method returns the size of the list {@link vector}.
 *
 * @param interval Interval
 * @return size of the list {@link vector}.
 */
int size_of_interval(Interval_ptr interval) {
    return interval->list->size;
}
