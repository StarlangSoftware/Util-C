//
// Created by Olcay Taner YILDIZ on 29.01.2024.
//

#include <ArrayList.h>
#include <Memory/Memory.h>

#include "../src/FileUtils.h"

int main(){
    start_medium_memory_check();
    Array_list_ptr lines = read_lines("penntreebank.txt");
    printf("%d", lines->size);
    free_array_list(lines, free_);
    end_memory_check();
}