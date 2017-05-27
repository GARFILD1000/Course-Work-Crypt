int WordToKey(int key[], char word[]);
int CheckSymbolLang(int symbol);
int VigenereCryptProcessing(int symbol, int key_symbol);
void StackFilesPath(char filename[], int InOrOut);
int VigenereCrypt(char word[]);
void VigenereWindow();
void ShowMessage(int result);

int CopyString(char string[], char copy[]){
    int i = 0;
    while (string[i] != 0){
        copy[i] = string[i];
        i++;
    };
    copy[i] = string[i];
    return 1;
}

//функция проверки символа на соответствие английскому или русскому алфавиту
//на вход получает номер сивола в таблице ASCII
//возвращает 1, если символ - русскоязычная буква
//возвращает 2, если символ - англоязычная буква
//возвращает 0, если символ не принадлежит этим алфавитам
int CheckSymbolLang(int symbol) {
    if ((symbol > 191) && (symbol < 256) || (symbol == 168) ||
        (symbol == 184)) {
        return 1;
    } else if (((symbol > 96) && (symbol < 123)) ||
               ((symbol > 54) && (symbol < 91))) {
        return 2;
    } else
        return 0;
}

//функция обрабатывающая шифруемый символ
//сдвигает символ symbol вправо по алфавиту на величину key_symbol
//символ 'Ё' и 'ё' обрабатывается как 'Е' и 'е' соответственно
int VigenereCryptProcessing(int symbol, int key_symbol) {
    int lang;
    lang = CheckSymbolLang(symbol);
    switch (lang) {
    case 0:
        return symbol;
    case 1:
        if (symbol == 168) {
            symbol = 197;
        };//символ Ё заменяется на Е
        if (symbol == 184) {
            symbol = 229;
        };//символ ё заменяется на е
        if ((symbol > 191) && (symbol < 224)) {
            symbol += key_symbol;
            if (symbol > 223) {
                symbol = symbol - 32;
            };
        }
        if ((symbol > 223) && (symbol < 256)) {
            symbol += key_symbol;
            if (symbol > 255) {
                symbol = symbol - 32;
            };
        }
        return symbol;
    case 2:
        if ((symbol > 64) && (symbol < 91)) {
            symbol += key_symbol;
            if (symbol > 90) {
                symbol = symbol - 26;
            };
        }
        if ((symbol > 96) && (symbol < 123)) {
            symbol += key_symbol;
            if (symbol > 122) {
                symbol = symbol - 26;
            };
        }
        return symbol;
    };
};

//функция, преобразующая слово (ключ шифра) в числовые значения сдвигов символов
//по алфавиту
int WordToKey(int key[], char word[]) {
    int i = 0, j = 0;
    while (word[i] != 0) {
        if (word[i] == -88) {
            word[i] = -59;
        };
        if (word[i] == -72) {
            word[i] = -27;
        };
        if ((word[i] < 0) && (word[i] > -33)) {
            key[j] = word[i] + 32;
            j++;
        } else if ((word[i] < -32) && (word[i] > -65)) {
            key[j] = word[i] + 64;
            j++;
        } else if ((word[i] > 64) && (word[i] < 91)) {
            key[j] = word[i] - 65;
            j++;
        } else if ((word[i] > 96) && (word[i] < 123)) {
            key[j] = word[i] - 97;
            j++;
        }
        i++;
    };
    key[j] = -1;//добавляется в массив, чтобы отслеживать конец ключа
}

//функция составляет полный путь к файлу
//складывая расположение каталга с файлами и название самого файла
//если InOrOut равен нулю, то берётся название входного файла из структуры
// options
//иначе берётся название выходного файла
//входной - input_file_name, выходной - output_file_name
void StackFilesPath(char filename[], int InOrOut) {
    int k = 0, j = 0;
    while ((options.file_directory[k] > 31) ||
           (options.file_directory[k] < 0)) {
        filename[k] = options.file_directory[k];
        k++;
    };
    if (!InOrOut) {
        while ((options.input_file_name[j] > 31) ||
               (options.input_file_name[j] < 0)) {
            filename[k] = options.input_file_name[j];
            k++;
            j++;
        };
    } else {
        while ((options.output_file_name[j] > 31) ||
               (options.output_file_name[j] < 0)) {
            filename[k] = options.output_file_name[j];
            k++;
            j++;
        };
    };
    filename[k] = 0;
};

//функция шифровки методом Виженера
//получает на вход слово - ключ шифра
//возвращает 1, если шифруемый файл не открылся
//возвращает 2, если файл с результатом шифровки не создаётся
//возвращает 3, если ключ шифра не задан или задан неправильно
//возвращает 4, если имена этих файлов совпадают
//возвращает 0, если шифровка прошла успешно
int VigenereCrypt(char word[]) {
    FILE *input_file;
    FILE *output_file;
    int *key, symbol, word_length = 0, key_length = 0, i = 0;
    char *output_filename, *input_filename;
    while (word[word_length] != 0) {
        word_length++;
    };
    printf("Длина полученного слова: %d \nСамо слово: %s\n", word_length - 1,
           word);
    key = new int[word_length];
    WordToKey(key, word);

    while (key[key_length] != -1) {
        key_length++;
    };

    printf("\nДлина ключа %d \nПолученный ключ шифра: \n", key_length);
    for (int j = 0; j < key_length; j++) {
        printf("%d ", key[j]);
    };
    printf("\n");
    if (key[0] == -1) {
        return 3;
    };

    input_filename = new char[100];
    output_filename = new char[100];
    StackFilesPath(input_filename, 0);
    StackFilesPath(output_filename, 1);
    printf("Входной файл %s\n", input_filename);
    printf("Выходной файл %s\n", output_filename);
    if (strcmp(input_filename, output_filename) == 0)
        return 4;
    printf("Открытие входного файла ");
    if ((input_file = fopen(input_filename, "r")) == NULL) {
        printf("Не открыл!");
        return 1;
    };
    printf("Завершено\n");
    printf("Создание выходного файла ");
    if ((output_file = fopen(output_filename, "w")) == NULL) {
        printf("Не создал!");
        return 2;
    };
    printf("Завершено\n");

    printf("Шифровка началась...\n");
    while ((symbol = fgetc(input_file)) != EOF) {
        // printf(" (%c %d) ",symbol, symbol);
        symbol = VigenereCryptProcessing(symbol, key[i]);
        // printf("=> (%c %d) \n",symbol, symbol);
        fputc(symbol, output_file);
        if (CheckSymbolLang(symbol) != 0) {
            if (i != key_length - 1)
                i++;
            else
                i = 0;
        };
    };
    printf("Зашифровано!\n");
    fclose(input_file);
    fclose(output_file);
    return 0;
};

//процедура выводит сообщение на экран в зависимости от параметра
//позволяет уведомлять пользователя об ошибках, если таковые возникают
//или об окончании процесса зашифровки / расшифровки
void ShowMessage(int result) {
    settextjustify(1, 1);
    settextstyle(1, 0, 3);
    bar(100, 100, 500, 300);
    if (!result) {
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
    } else {
        setcolor(RGB(negative_color.red, negative_color.green,
                     negative_color.blue));
    };
    rectangle(100, 100, 500, 300);
    switch (result) {
    case 0:
        outtextxy(300, 200, "Зашифровано!");
        break;
    case 1:
        outtextxy(300, 180, "Неверно назван");
        outtextxy(300, 220, "файл для зашифровки!");
        break;
    case 2:
        outtextxy(300, 180, "Неверно назван");
        outtextxy(300, 220, "файл с результатом!");
        break;
    case 3:
        outtextxy(300, 180, "Введите");
        outtextxy(300, 220, "правильный ключ!");
        break;
    case 4:
        outtextxy(300, 160, "Файлы не должны");
        outtextxy(300, 200, "совпадать");
        outtextxy(300, 240, "по названию!");
        break;
    case 5:
        outtextxy(300, 200, "Расшифровано!");
        break;
    };
    getch();
}


//меню зашифровки методом Виженера
void VigenereCryptWindow() {
    char *input_filename, *output_filename, *word, *temp_word;
    int k = 0;
    input_filename = new char[50];
    output_filename = new char[50];
    word = new char[50];
    temp_word = new char[50];
    word[0] = 0;
    temp_word[0] = 0;
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
        outtextxy(300, 50, "Шифр Виженера");
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
        outtextxy(300, 260, "Введите ключ шифра");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 340, "Зашифровать!");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 5) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "Назад");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        InputBox(100, 110, 0, options.input_file_name);
        InputBox(100, 190, 0, options.output_file_name);
        InputBox(100, 270, 0, word);
        button = getch();
        switch (button) {
        case 72:
            if (point > 1) {
                point--;
            };
            break;
        case 80:
            if (point < 5) {
                point++;
            };
            break;
        case 13:
            switch (point) {
            case 1:
                printf("Открывается поле ввода\n");
                char *temp_string;
                //файл, в который загрузится список файлов
                temp_string = "..\\saves\\filelist.txt";  
                CopyString(temp_string, options.cache_file_name);  
                //запуск батника, который заполнит файл списком файлов
                ShellExecute(FindWindow(NULL, "Шифратор"), "open", "..\\binary\\MakeFileList.bat", NULL, NULL, SW_HIDE);
                InputBox(100, 110, 1, options.input_file_name);
                temp_string = "..\\saves\\cache.txt";
                CopyString(temp_string, options.cache_file_name);
                printf("\nВведено: ");
                printf("%s ", input_filename);
                break;
            case 2:
                printf("Открывается поле ввода\n");
                InputBox(100, 190, 1, options.output_file_name);
                printf("\nВведено: ");
                printf("%s ", output_filename);
                break;
            case 3:
                printf("Открывается поле ввода\n");
                if (InputBox(100, 270, 1, temp_word)) {
                    word = temp_word;
                };
                printf("\nВведено: ");
                printf("%s ", word);
                for (int i = 0;; i++)
                    if (word[i] == 0) {
                        word[i] = 13;
                        word[i + 1] = 0;
                        break;
                    };
                break;
            case 4:
                int result;
                result = VigenereCrypt(word);
                ShowMessage(result);
                break;
            case 5:
                return;
            };
            break;
        case 27:
            return;
        };
    } while (1);
}
