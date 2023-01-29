//
// Created by Olcay Taner YILDIZ on 28.01.2023.
//

#ifndef UTIL_SUBSETFROMLIST_H
#define UTIL_SUBSETFROMLIST_H

struct subset_from_list{
    int* set;
    int element_count;
    int* element_list;
    int* index_list;
    int list_size;
};

typedef struct subset_from_list Subset_from_list;
typedef Subset_from_list* Subset_from_list_ptr;

Subset_from_list_ptr create_subset_from_list(int* list, int list_size, int element_count);
void free_subset_from_list(Subset_from_list_ptr subset);
int next_subset_from_list(Subset_from_list_ptr subset);

#endif //UTIL_SUBSETFROMLIST_H
