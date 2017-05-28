int CezarDecrypt(int n);
void CezarDecryptWindow();

//функция расшифровки методом Цезаря
//получает на вход ключ шифра
//возвращает 1, если зашифрованный файл не открылся
//возвращает 2, если файл с результатом расшифровки не создаётся
//возвращает 4, если имена этих файлов совпадают
//возвращает 0, если расшифровка прошла успешно
int CezarDecrypt(int n) {
    FILE *fp1, *fp2;
    char *output_filename, *input_filename;

    input_filename = new char[150];
    output_filename = new char[150];
    StackString(options.file_directory, options.input_file_name, input_filename);
    StackString(options.file_directory, options.output_file_name, output_filename);
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
    printf("Создание выходного файла...");
    if ((fp2 = fopen(output_filename, "w")) == NULL) {
        printf("Не создал!");
        return 2;
    };
    printf("Завершено\n");
    printf("Расшифровка началась...\n");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1)) {
        flag = 0;
        if (c >= 'A' && c <= 'Z') {
            c = c - (n % ENG);
            if (c < 'A')
                c = 'Z' - ('A' - c) + 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z') {
            c = c - (n % ENG);
            if (c < 'a')
                c = 'z' - ('a' - c) + 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'А' && c <= 'Я') {
            c = c - (n % RUS);
            if (c < 'А')
                c = 'Я' - ('А' - c) + 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'а' && c <= 'я') {
            c = c - (n % RUS);
            if (c < 'а')
                c = 'я' - ('а' - c) + 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (!flag)
            fprintf(fp2, "%c", c);
        c = getc(fp1);
    }
    printf("Расшифровано!\n");
    fclose(fp1);
    fclose(fp2);
    return 5;
}

//меню расшифровки методом Цезаря
void CezarDecryptWindow() {
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
        outtextxy(300, 50, "Шифр Цезаря");
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
        outtextxy(300, 260, "Введите ключ шифра");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 340, "Расшифровать!");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 5) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "Назад");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        InputBox(100, 110, 0, options.input_file_name);
        InputBox(100, 190, 0, options.output_file_name);
        SetNumberBox(250, 270, 0, num);
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
                char *filelist_path;
                //файл, в который загрузится список файлов
                filelist_path = new char [150];
                StackString(options.file_directory, "filelist", filelist_path);
                CopyString(filelist_path, options.cache_file_name);  
                //запуск батника, который заполнит файл списком файлов
                ShellExecute(FindWindow(NULL, "Шифратор"), "open", "..\\binary\\MakeFileList.bat", NULL, NULL, SW_HIDE);
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
                SetNumberBox(250, 270, 1, num);
                printf("\nВведено: ");
                printf("%d \n", num);
                break;
            case 4:
                printf("Активируется объект SetNumber\n");
                int result;
                result = CezarDecrypt(num);
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
