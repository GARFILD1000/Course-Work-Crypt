int VigenereDecryptProcessing(int symbol, int key_symbol);
int VigenereDecrypt(char word[]);
void VigenereDecryptWindow();

//�������, ���������� ������ symbol ����� �� �������� �� �������� key_symbol
int VigenereDecryptProcessing(int symbol, int key_symbol) {
    int lang;
    lang = CheckSymbolLang(symbol);

    switch (lang) {
    case 0:
        return symbol;
    case 1:
        if ((symbol > 191) && (symbol < 224)) {
            symbol -= key_symbol;
            if (symbol < 190) {
                symbol = symbol + 32;
            };
        }
        if ((symbol > 223) && (symbol < 256)) {
            symbol -= key_symbol;
            if (symbol < 224) {
                symbol = symbol + 32;
            };
        }
        return symbol;
    case 2:
        if ((symbol > 64) && (symbol < 91)) {
            symbol -= key_symbol;
            if (symbol < 65) {
                symbol = symbol + 26;
            };
        }
        if ((symbol > 96) && (symbol < 123)) {
            symbol -= key_symbol;
            if (symbol < 97) {
                symbol = symbol + 26;
            };
        }
        return symbol;
    };
};

//������� ����������� ������� ��������, �������� �� ���� ����� - ���� �����
int VigenereDecrypt(char word[]) {
    FILE *input_file;
    FILE *output_file;
    int *key, symbol, word_length = 0, key_length = 0, i = 0;
    char *output_filename, *input_filename;
    while (word[word_length] != 0) {
        word_length++;
    };
    printf("����� ����������� �����: %d \n���� �����: %s\n", word_length - 1,
           word);
    key = new int[word_length];
    WordToKey(key, word);

    while (key[key_length] != -1) {
        key_length++;
    };

    printf("\n����� ����� %d \n���������� ���� �����: \n", key_length);
    for (int j = 0; j < key_length; j++) {
        printf("%d ", key[j]);
    };
    printf("\n");
    if (key[0] == -1) {
        return 3;
    };

    input_filename = new char[150];
    output_filename = new char[150];
    StackString(options.file_directory, options.input_file_name, input_filename);
    StackString(options.file_directory, options.output_file_name, output_filename);
    printf("������� ���� %s\n", input_filename);
    printf("�������� ���� %s\n", output_filename);
    if (strcmp(input_filename, output_filename) == 0) {
        return 4;
    };
    printf("�������� �������� ����� ");
    if ((input_file = fopen(input_filename, "r")) == NULL) {
        printf("�� ������!");
        return 1;
    };
    printf("���������\n");
    printf("�������� ��������� ����� ");
    if ((output_file = fopen(output_filename, "w")) == NULL) {
        printf("�� ������!");
        return 2;
    };
    printf("���������\n");

    printf("����������� ��������...\n");
    while ((symbol = fgetc(input_file)) != EOF) {
        // printf(" (%c %d) ",symbol, symbol);
        symbol = VigenereDecryptProcessing(symbol, key[i]);
        // printf("=> (%c %d) \n",symbol, symbol);
        fputc(symbol, output_file);
        if (CheckSymbolLang(symbol) != 0) {
            if (i != key_length - 1) {
                i++;
            } else {
                i = 0;
            };
        };
    };
    printf("������������!\n");
    fclose(input_file);
    fclose(output_file);
    return 5;
};

void VigenereDecryptWindow() {//���� ���������� ������� ��������
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
        outtextxy(300, 50, "���� ��������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 100, "�������� ������������� ����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 180, "�������� �������������� ����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 260, "������� ���� �����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 340, "������������!");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 5) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "�����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        InputBox(100, 110, 0, options.input_file_name);
        InputBox(100, 190, 0, options.output_file_name);
        InputBox(100, 270, 0, word);
        button = getch();
        switch (button) {
        case 72:
            if (point > 1)
                point--;
            break;
        case 80:
            if (point < 5)
                point++;
            break;
        case 13:
            switch (point) {
            case 1:
                printf("����������� ���� �����\n");
                char *filelist_path;
                //����, � ������� ���������� ������ ������
                filelist_path = new char [150];
                StackString(options.file_directory, "filelist", filelist_path);
                CopyString(filelist_path, options.cache_file_name);  
                //������ �������, ������� �������� ���� ������� ������
                ShellExecute(FindWindow(NULL, "��������"), "open", "..\\binary\\MakeFileList.bat", NULL, NULL, SW_HIDE);
                InputBox(100, 110, 1, options.input_file_name);
                remove(filelist_path);
                CopyString("..\\saves\\cache.txt", options.cache_file_name);
                printf("\n�������: ");
                printf("%s ", input_filename);
                break;
            case 2:
                printf("����������� ���� �����\n");
                InputBox(100, 190, 1, options.output_file_name);
                printf("\n�������: ");
                printf("%s ", output_filename);
                break;
            case 3:
                printf("����������� ���� �����\n");
                if (InputBox(100, 270, 1, temp_word))
                    word = temp_word;
                printf("\n�������: ");
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
                result = VigenereDecrypt(word);
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
