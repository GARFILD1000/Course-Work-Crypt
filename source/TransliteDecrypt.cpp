#include <graphics.h>
#include <stdlib.h>
#include "Struct.h"

void StackString(char string1[], char string2[], char result[]);
int CopyString(char string[], char copy[]);
int InputBox(int x1, int y1, short active, char word[]);
void ShowMessage(int result);

extern struct Options options;
extern struct Color bg_color, point_color, punkt_color, word_color, temp_color,
        negative_color;

//функция расшифровки методом Транслит
//возвращает 1, если шифруемый файл не открылся
//возвращает 2, если файл с результатом шифровки не создаётся
//возвращает 4, если имена этих файлов совпадают
//возвращает 5, если расшифровка прошла успешно
int TransliteDecrypt (){
	setlocale(LC_ALL, "rus");
	FILE *fp1, *fp2;
	char ch = 'q';
	char *output_filename, *input_filename;

    input_filename = new char[150];
    output_filename = new char[150];
    StackString(options.file_directory, options.input_file_name,
                input_filename);
    StackString(options.file_directory, options.output_file_name,
                output_filename);
    printf("Входной файл %s\n", input_filename);
    printf("Выходной файл %s\n", output_filename);
    if (strcmp(input_filename, output_filename) == 0)
        return 4;
    printf("Открытие входного файла ");
    if ((fp1 = fopen(input_filename, "r")) == NULL) {
        printf("Не открыл!");
        return 1;
    };
    printf("Завершено\n");
    printf("Создание выходного файла ");
    if ((fp2 = fopen(output_filename, "w")) == NULL) {
        printf("Не создал!");
        return 2;
    };
    printf("Завершено\n");
    printf("Шифровка началась...\n");
	
    while (!feof(fp1)){
    	ch = getc(fp1);                      
    	switch (ch){
            case 'f': ch = 'а'; break;
        	case ',': ch = 'б'; break;
        	case 'd': ch = 'в'; break;
            case 'u': ch = 'г'; break;
            case 'l': ch = 'д'; break;
            case 't': ch = 'е'; break;
            case '`': ch = 'ё'; break;
            case ';': ch = 'ж'; break;
            case 'p': ch = 'з'; break;
            case 'b': ch = 'и'; break;
            case 'q': ch = 'й'; break;
            case 'r': ch = 'к'; break;
            case 'k': ch = 'л'; break;
            case 'v': ch = 'м'; break;
            case 'y': ch = 'н'; break;
        	case 'j': ch = 'о'; break;
            case 'g': ch = 'п'; break;
            case 'h': ch = 'р'; break;
            case 'с': ch = 'с'; break;
            case 'n': ch = 'т'; break;
            case 'e': ch = 'у'; break;
            case 'a': ch = 'ф'; break;
            case '[': ch = 'х'; break;
            case 'w': ch = 'ц'; break;
            case 'x': ch = 'ч'; break;
            case 'i': ch = 'ш'; break;
            case 'o': ch = 'щ'; break;
            case ']': ch = 'ъ'; break;
            case 's': ch = 'ы'; break;
            case 'm': ch = 'ь'; break;
            case 39: ch = 'э'; break;
            case '.': ch = 'ю'; break;
            case 'z': ch = 'я'; break;
            case 'F': ch = 'А'; break;
            case '<': ch = 'Б'; break;
            case 'D': ch = 'В'; break;
            case 'U': ch = 'Г'; break;
            case 'L': ch = 'Д'; break;
            case 'T': ch = 'Е'; break;
            case '~': ch = 'Ё'; break;
            case ':': ch = 'Ж'; break;
            case 'P': ch = 'З'; break;
            case 'B': ch = 'И'; break;
            case 'Q': ch = 'Й'; break;
            case 'R': ch = 'К'; break;
            case 'K': ch = 'Л'; break;
            case 'V': ch = 'М'; break;
            case 'Y': ch = 'Н'; break;
            case 'J': ch = 'О'; break;
            case 'G': ch = 'П'; break;
            case 'H': ch = 'Р'; break;
            case 'C': ch = 'С'; break;
            case 'N': ch = 'Т'; break;
            case 'E': ch = 'У'; break;
            case 'A': ch = 'Ф'; break;
            case '{': ch = 'Х'; break;
            case 'W': ch = 'Ц'; break;
            case 'X': ch = 'Ч'; break;
            case 'I': ch = 'Ш'; break;
            case 'O': ch = 'Щ'; break;
            case '}': ch = 'Ъ'; break;
            case 'S': ch = 'Ы'; break;
            case 'M': ch = 'Ь'; break;
            case '"': ch = 'Э'; break;
            case '>': ch = 'Ю'; break;
            case 'Z': ch = 'Я'; break;
		}
    	putc(ch,fp2);                    
    }
    fclose (fp1);
    fclose (fp2);
    return 5;
}

//меню расшифровки методом Транслит
void TransliteDecryptWindow() {
    char *input_filename, *output_filename, *word;
    int k = 0, num = 1;
    input_filename = new char[50];
    output_filename = new char[50];
    do {
        input_filename[k] = options.input_file_name[k];
        k++;
    } while (options.input_file_name[k - 1] != 0);
    k = 0;
    do {
        output_filename[k] = options.output_file_name[k];
        k++;
    } while (options.output_file_name[k - 1] != 0);
    k = 0;
    input_filename = options.input_file_name;
    output_filename = options.output_file_name;
    int button, point = 1;
    do {
        cleardevice();
        settextjustify(1, 1);
        settextstyle(1, 0, 5);
        setcolor(RGB(negative_color.red, negative_color.green,
                     negative_color.blue));
        outtextxy(300, 50, "Шифр Транслит");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 100, "Назовите зашифрованный файл");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 180, "Назовите расшифрованный файл");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 340, "Расшифровать!");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "Назад");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        InputBox(100, 110, 0, options.input_file_name);
        InputBox(100, 190, 0, options.output_file_name);
        button = getch();
        switch (button) {
        case 72:
            if (point > 1) {
                point--;
            };
            break;
        case 80:
            if (point < 4) {
                point++;
            };
            break;
        case 13:
            switch (point) {
            case 1:
                printf("Открывается поле ввода\n");
                char *filelist_path;
                //файл, в который загрузится список файлов
                filelist_path = new char[150];
                StackString(options.file_directory, "filelist", filelist_path);
                CopyString(filelist_path, options.cache_file_name);
                //запуск батника, который заполнит файл списком файлов
                ShellExecute(FindWindow(NULL, "Шифратор"), "open",
                             "..\\binary\\MakeFileList.bat", NULL, NULL,
                             SW_HIDE);
                InputBox(100, 110, 1, options.input_file_name);
                remove(filelist_path);
                CopyString("..\\saves\\cache.txt", options.cache_file_name);
                printf("\nВведено: ");
                printf("%s \n", input_filename);
                break;
            case 2:
                printf("Открывается поле ввода\n");
                InputBox(100, 190, 1, options.output_file_name);
                printf("\nВведено: ");
                printf("%s \n", output_filename);
                break;
            case 3:
                int result;
                result = TransliteDecrypt();
                ShowMessage(result);
                break;
            case 4:
                return;
            };
            break;
        case 27:
            return;
        };
    } while (1);
}
