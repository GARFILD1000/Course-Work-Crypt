#ifndef STRUCT_H
#define STRUCT_H

#define ENG 26
#define RUS 32

//структуры цвета, хранят RGB-значения каждого цвета
struct Options {
    char input_file_name[50];
    char output_file_name[50];
    char file_directory[100];
    int console_on;
    char cache_file_name[50];
};

//структуры цвета, хранят RGB-значения каждого цвета
struct Color {
    int red;
    int green;
    int blue;
};

#endif
