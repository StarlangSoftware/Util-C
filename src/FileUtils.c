//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#include <string.h>
#include "FileUtils.h"
#include "StringUtils.h"

Array_list_ptr read_items(FILE *input_file, char delimiter) {
    char ch = fgetc(input_file);
    char buffer[MAX_LINE_LENGTH];
    char* item;
    int index = 0;
    Array_list_ptr result = create_array_list();
    while (ch != '\n' && ch != EOF){
        if (ch != delimiter){
            buffer[index] = ch;
            index++;
        } else {
            buffer[index] = '\0';
            if (strlen(buffer) > 0){
                item = str_copy(item, buffer);
                array_list_add(result, item);
            }
            index = 0;
        }
        ch = fgetc(input_file);
    }
    buffer[index] = '\0';
    if (strlen(buffer) > 0){
        item = str_copy(item, buffer);
        array_list_add(result, item);
    }
    return result;
}

Array_list_ptr read_lines(const char *file_name) {
    FILE* input_file;
    char line[MAX_LINE_LENGTH];
    Array_list_ptr result = create_array_list();
    input_file = fopen(file_name, "r");
    char* input = fgets(line, MAX_LINE_LENGTH, input_file);
    while (input != NULL){
        line[strcspn(line, "\n")] = 0;
        char* copy = str_copy(copy, line);
        array_list_add(result, copy);
        input = fgets(line, MAX_LINE_LENGTH, input_file);
    }
    fclose(input_file);
    return result;
}
