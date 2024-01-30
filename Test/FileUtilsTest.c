//
// Created by Olcay Taner YILDIZ on 29.01.2024.
//

#include <ArrayList.h>
#include "../src/FileUtils.h"

int main(){
    Array_list_ptr lines = read_lines("penntreebank.txt");
    printf("%d", lines->size);
}