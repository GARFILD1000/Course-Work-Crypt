#include <stdlib.h>
#include <graphics.h>
#include "Struct.h"

void StackString(char string1[], char string2[], char result[]);

extern struct Options options;
extern struct Color bg_color, point_color, punkt_color, word_color, temp_color,
        negative_color;


int WordToCache(char word[]) {
    FILE *cache_file;
    FILE *temp_file;
    int symbol;
    int num = 1, i = 0;
    if ((cache_file = fopen(options.cache_file_name, "r+")) == NULL) {
        printf("Файл с кэшем не открылся ");
        fclose(cache_file);
        cache_file = fopen(options.cache_file_name, "w+");
        printf("создался новый\n");
    };
    if ((word[0] == 13) || (word[0] == 0)) {
        fclose(cache_file);
        return 0;
    };
    
    int j = 0, k = 0;
    char temp_file_name[50], *temp_string;
    temp_string = "temp_file.txt";
    while (options.cache_file_name[j] != 0){
        j++;
    };
    while ((options.cache_file_name[j] != 92) && (options.cache_file_name[j] != 47)) {
        j--;
    };
    for (k = 0; k <= j; k++){
        temp_file_name[k] = options.cache_file_name[k];
    };
    j = 0;
    while (temp_string[j] != 0){
        temp_file_name[k] = temp_string[j];
        j++;
        k++;
    };
    temp_file_name[k] = 0;
    
    temp_file = fopen(temp_file_name, "w+");
    while (word[i] != 0) {
        fputc(word[i], temp_file);
        i++;
    };
    fputc(10, temp_file);
    while ((symbol = fgetc(cache_file)) != EOF) {
        fputc(symbol, temp_file);
    };
    fclose(cache_file);
    fclose(temp_file);
    if (remove(options.cache_file_name)) {
        printf("Ошибка удаления\n");
        perror("Проблема в ");
        return 0;
    };
    if (rename(temp_file_name, options.cache_file_name)){
        printf("Oшибка переименования\n");
        return 0;
    };
    printf("Строка %s добавлена в кэш-файл \n", word);
    return 1;
}

int WordFromCache(char word[], int num_of_word) {
    FILE *cache_file;
    int symbol;
    int num = 1, i = 0;
    if (num_of_word <= 0)
        return 0;
    if ((cache_file = fopen(options.cache_file_name, "r")) == NULL) {
        printf("Файла с кэшем нет,создаётся новый... ");
        fclose(cache_file);
        cache_file = fopen(options.cache_file_name, "w");
        printf("создано!\n");
        fputc(0, cache_file);
        fclose(cache_file);
        return 0;
    };
    if (num < num_of_word) {
        while ((symbol = fgetc(cache_file)) != EOF) {
            if (symbol == 10) {
                num++;
                if (num == num_of_word) {
                    break;
                };
            };
        };
    };
    if (num < num_of_word) {
        fclose(cache_file);
        return 0;
    };
    while ((symbol = fgetc(cache_file)) != EOF) {
        if (symbol == 10) {
            break;
        };
        word[i] = symbol;
        i++;
    };
    word[i] = 0;
    fclose(cache_file);
    return 1;
}

int CutWord(char word[], char cut_word[], int first, int last) {
    if (first > last) {
        return 0;
    };
    int j = 0;
    for (int i = first; i <= last; i++) {
        cut_word[j] = word[i];
        j++;
    };
    cut_word[j] = 0;
    return 1;
}

//функция удаления символа с порядковым номером num
//из строки word
//возвращает 1, если символ был удалён, иначе 0
int DeleteSymbol(char word[], int num) {
    int i = 0;
    while (word[i] != 0) i++;
    if (num >= i) {
        return 0;
    };
    for (int i = num; word[i] != 0; i++) {
        word[i] = word[i + 1];
    };
    return 1;
}

//функция добавляет символ symbol в строку word
//после символа с порядковым номером num
//возвращает 1, если символ добавлен, иначе 0
int AddSymbol(char word[], char symbol, int num) {
    int i = 0;
    char temp;
    temp = word[i];
    while (word[i] != 0) i++;
    if (num > i) {
        return 0;
    };
    while (i >= num) {
        word[i + 1] = word[i];
        i--;
    };
    word[num] = symbol;
    return 1;
}

//функция, изображающая поле ввода строки
//ввод активен, если параметр active ненулевой
//позволяет добавлять символы в строку, удалять их клавишей backspase
//и перемещаться по вводимой строке клавишами со стрелками
int InputBox(int x1, int y1, short active, char word[]) {
    setlinestyle(0, 0, 2);
    settextstyle(8, 0, 2);
    settextjustify(0, 0);
    setfillstyle(0, RGB(bg_color.red, bg_color.green, bg_color.blue));
    bar(x1, y1, x1 + 400, y1 + 40);
    char *temp_word;
    char button;
    int x = x1 + 5, y = y1 + 30, word_size = 0, left_barrier = 0, box_size = 32;
    for (word_size = 0; word[word_size] != 0; word_size++) {
        if (word[word_size] == 13) {
            word[word_size] == 0;
            break;
        };
    };
    temp_word = new char[box_size + 1];
    CutWord(word, temp_word, left_barrier, left_barrier + box_size - 1);

    if (active) {
        int cursor, cursor_x, moving = 0, num_of_word = 0;
        if (word_size > box_size) {
            left_barrier = word_size - box_size;
        };
        cursor = word_size - left_barrier;
        do {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
            bar(x1, y1, x1 + 400, y1 + 40);
            rectangle(x1, y1, x1 + 400, y1 + 40);
            setcolor(RGB(word_color.red, word_color.green, word_color.blue));
            cursor_x = x + (cursor - left_barrier) * 12;
            line(cursor_x + 2, y + 5, cursor_x + 10, y + 5);
            CutWord(word, temp_word, left_barrier, left_barrier + box_size - 1);
            outtextxy(x, y, temp_word);
            button = getch();
            if (moving == 0) {
                if (button == 13) {
                    cursor = word_size;
                };
                if ((word_size < 49) &&
                    ((button >= 32) || (button < 0) || (button == 13))) {
                    AddSymbol(word, button, cursor);
                    word_size++;
                    word[word_size] = 0;
                    if (word_size > box_size) {
                        left_barrier++;
                    };
                    cursor++;
                };
                switch (button) {
                case 8:
                    if ((word_size >= 0) && (cursor != 0)) {
                        DeleteSymbol(word, cursor - 1);
                        if (word_size != 0) {
                            if (word[0] != 0) {
                                word_size--;
                            };
                            if (left_barrier > 0) {
                                left_barrier--;
                            };
                        };
                        if (cursor > 0) {
                            cursor--;
                        };
                    };
                    break;
                case 13:
                    word[word_size-1] = 0;
                    WordToCache(word);
                    return 1;
                case 27:
                    return 0;
                }
            } else {
                switch (button) {
                case 75:
                    if (cursor > left_barrier) {
                        cursor--;
                    } else if (left_barrier > 0) {
                        cursor--;
                        left_barrier--;
                    };
                    break;
                case 77:
                    if ((cursor < left_barrier + box_size) &&
                        (cursor < word_size))
                        cursor++;
                    else if ((cursor < word_size) &&
                             ((left_barrier + box_size) < word_size)) {
                        cursor++;
                        left_barrier++;
                    };
                    break;
                case 46:
                    if (word_size >= 0) {
                        DeleteSymbol(word, cursor);
                        if (word_size != 0) {
                            if (word[0] != 0)
                                word_size--;
                            if (left_barrier > 0)
                                left_barrier--;
                        };
                    };
                case 72:
                    if (WordFromCache(word, num_of_word + 1)) {
                        num_of_word++;
                    };
                    for (word_size = 0; word[word_size] != 0; word_size++)
                        ;
                    cursor = box_size;
                    printf("Номер слова из кэша %d \n", num_of_word);
                    if (word_size > box_size) {
                        left_barrier = word_size - box_size;
                    } else {
                        left_barrier = 0;
                    };
                    cursor = word_size;
                    break;
                case 80:
                    if (num_of_word > 0) {
                        num_of_word--;
                        WordFromCache(word, num_of_word);
                        if (num_of_word == 0) {
                            word[0] = 0;
                        };
                        for (word_size = 0; word[word_size] != 0; word_size++)
                            ;
                        if (word_size > box_size) {
                            left_barrier = word_size - box_size;
                        } else {
                            left_barrier = 0;
                        };
                        cursor = word_size;
                        printf("Номер слова из кэша %d \n", num_of_word);
                    };
                    break;
                };
                moving = 0;
            };
            if (button == 0) {
                moving = 1;
            } else {
                moving = 0;
            };
        } while (1);
    } else {
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        rectangle(x1, y1, x1 + 400, y1 + 40);
        outtextxy(x, y, temp_word);
        return 0;
    };
}
