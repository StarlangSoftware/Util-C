//
// Created by Olcay Taner YILDIZ on 27.01.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "RandomArray.h"

/**
 * The constructor of RandomNormalizedArray class gets an integer itemCount as an input. Creates an array of
 * size itemCount and loops through each element of the array and initializes them with a random number by using rand.
 * Then, accumulates each element of the array and at the end divides each element with the resulting sum.
 *
 * @param item_count integer input defining array size.
 */
double *normalized_array(int item_count) {
    int i;
    double sum = 0.0;
    double *array = malloc_(item_count * sizeof(double), "normalized_array");
    for (i = 0; i < item_count; i++) {
        array[i] = random() / (RAND_MAX + 1.0);
        sum += array[i];
    }
    for (i = 0; i < item_count; i++) {
        array[i] /= sum;
    }
    return array;
}

/**
 * Creates and returns a random index array, where the indexes in the array are between 0 and itemCount - 1.
 * @param itemCount Number of indexes
 * @param random Random number generator
 * @return Randomized array containing numbers between 0 and itemCount - 1.
 */
Array_list_ptr index_array(int item_count, int seed) {
    Array_list_ptr random_array = create_array_list();
    for (int i = 0; i < item_count; i++) {
        array_list_add_int(random_array, i);
    }
    array_list_shuffle(random_array, seed);
    return random_array;
}
