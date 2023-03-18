//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#include "FileUtils.h"
#include "StringUtils.h"

Array_list_ptr read_items(FILE *input_file, char delimiter) {
    char ch = fgetc(input_file);
    char buffer[1000];
    char* item;
    int index = 0;
    Array_list_ptr result = create_array_list();
    while (ch != '\n' && ch != EOF){
        if (ch != delimiter){
            buffer[index] = ch;
            index++;
        } else {
            buffer[index] = '\0';
            item = str_copy(item, buffer);
            array_list_add(result, item);
            index = 0;
        }
        ch = fgetc(input_file);
    }
    return result;
}
