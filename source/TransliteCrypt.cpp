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

//функция шифровки методом Цезаря
//на вход получает величину сдвига по алфавиту
//возвращает 1, если шифруемый файл не открылся
//возвращает 2, если файл с результатом шифровки не создаётся
//возвращает 4, если имена этих файлов совпадают
//возвращает 0, если шифровка прошла успешно
int TransliteCrypt (){
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
            case 'а': ch = 'f'; break;
        	case 'б': ch = ','; break;
        	case 'в': ch = 'd'; break;
            case 'г': ch = 'u'; break;
            case 'д': ch = 'l'; break;
            case 'е': ch = 't'; break;
            case 'ё': ch = '`'; break;
            case 'ж': ch = ';'; break;
            case 'з': ch = 'p'; break;
            case 'и': ch = 'b'; break;
            case 'й': ch = 'q'; break;
            case 'к': ch = 'r'; break;
            case 'л': ch = 'k'; break;
            case 'м': ch = 'v'; break;
            case 'н': ch = 'y'; break;
        	case 'о': ch = 'j'; break;
            case 'п': ch = 'g'; break;
            case 'р': ch = 'h'; break;
            case 'с': ch = 'c'; break;
            case 'т': ch = 'n'; break;
            case 'у': ch = 'e'; break;
            case 'ф': ch = 'a'; break;
            case 'х': ch = '['; break;
            case 'ц': ch = 'w'; break;
            case 'ч': ch = 'x'; break;
            case 'ш': ch = 'i'; break;
            case 'щ': ch = 'o'; break;
            case 'ъ': ch = ']'; break;
            case 'ы': ch = 's'; break;
            case 'ь': ch = 'm'; break;
            case 'э': ch = 39; break;
            case 'ю': ch = '.'; break;
            case 'я': ch = 'z'; break;
            case 'А': ch = 'F'; break;
            case 'Б': ch = '<'; break;
            case 'В': ch = 'D'; break;
            case 'Г': ch = 'U'; break;
            case 'Д': ch = 'L'; break;
            case 'Е': ch = 'T'; break;
            case 'Ё': ch = '~'; break;
            case 'Ж': ch = ':'; break;
            case 'З': ch = 'P'; break;
            case 'И': ch = 'B'; break;
            case 'Й': ch = 'Q'; break;
            case 'К': ch = 'R'; break;
            case 'Л': ch = 'K'; break;
            case 'М': ch = 'V'; break;
            case 'Н': ch = 'Y'; break;
            case 'О': ch = 'J'; break;
            case 'П': ch = 'G'; break;
            case 'Р': ch = 'H'; break;
            case 'С': ch = 'C'; break;
            case 'Т': ch = 'N'; break;
            case 'У': ch = 'E'; break;
            case 'Ф': ch = 'A'; break;
            case 'Х': ch = '{'; break;
            case 'Ц': ch = 'W'; break;
            case 'Ч': ch = 'X'; break;
            case 'Ш': ch = 'I'; break;
            case 'Щ': ch = 'O'; break;
            case 'Ъ': ch = '}'; break;
            case 'Ы': ch = 'S'; break;
            case 'Ь': ch = 'M'; break;
            case 'Э': ch = '"'; break;
            case 'Ю': ch = '>'; break;
            case 'Я': ch = 'Z'; break;
		}
	    putc(ch,fp2);                    
    }
    fclose (fp1);
    fclose (fp2);
    return 0;
}

//меню зашифровки методом Цезаря
void TransliteCryptWindow() {
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
        outtextxy(300, 100, "Назовите исходный файл");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 180, "Назовите зашифрованный файл");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 340, "Зашифровать!");
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
                result = TransliteCrypt();
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

