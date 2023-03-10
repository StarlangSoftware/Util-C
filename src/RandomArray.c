//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#include <stdlib.h>
#include "RandomArray.h"

/**
 * The constructor of {@link RandomNormalizedArray} class gets an integer itemCount as an input. Creates an array of
 * size itemCount and loops through each element of the array and initializes them with a random number by using rand.
 * Then, accumulates each element of the array and at the end divides each element with the resulting sum.
 *
 * @param item_count integer input defining array size.
 */
double *normalized_array(int item_count) {
    int i;
    double sum = 0.0;
    double *array = malloc(item_count * sizeof(double));
    for (i = 0; i < item_count; i++) {
        array[i] = random() / (RAND_MAX + 1.0);
        sum += array[i];
    }
    for (i = 0; i < item_count; i++) {
        array[i] /= sum;
    }
    return array;
}

Array_list_ptr indexArray(int item_count, int seed) {
    srand(seed);
    Array_list_ptr random_array = create_array_list();
    for (int i = 0; i < item_count; i++) {
        int *number = malloc(sizeof(int));
        *number = i;
        array_list_add(random_array, number);
    }
    array_list_shuffle(random_array);
    return random_array;
}
