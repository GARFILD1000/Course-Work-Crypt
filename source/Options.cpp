#include <graphics.h>
#include <stdlib.h>
#include "Struct.h"

int InputBox(int x1, int y1, short active, char word[]);
void RestoreOptionsWindow();

extern struct Options options;
extern struct Color bg_color, point_color, punkt_color, word_color, temp_color,
        negative_color;

void ChangeBatDirectory() {
    FILE *bat_file, *temp_file;
    int i = 9, symbol;
    char command[100];

    command[0] = 'c';
    command[1] = 'h';
    command[2] = 'd';
    command[3] = 'i';
    command[4] = 'r';
    command[5] = ' ';
    command[6] = '/';
    command[7] = 'd';
    command[8] = ' ';
    while (options.file_directory[i - 9] != 0) {
        command[i] = options.file_directory[i - 9];
        i++;
    };
    command[i] = options.file_directory[i];
    printf("�������� ������� ");
    if ((bat_file = fopen("..\\binary\\MakeFileList.bat", "rt+")) == NULL) {
        printf("��������!");
    };
    printf("���������\n");
    temp_file = fopen("..\\binary\\temp.txt", "wt+");
    while ((symbol = fgetc(bat_file)) != 10) {
        fputc(symbol, temp_file);
    };
    fputc(10, temp_file);
    while (fgetc(bat_file) != 10)
        ;
    fputs(command, temp_file);
    fputc(10, temp_file);
    while ((symbol = fgetc(bat_file)) != EOF) {
        fputc(symbol, temp_file);
    };
    fclose(temp_file);
    fclose(bat_file);
    remove("..\\binary\\MakeFileList.bat");
    rename("..\\binary\\temp.txt", "..\\binary\\MakeFileList.bat");
    return;
}

void InputPathWindow() {
    int button, point = 1;
    do {
        cleardevice();
        settextjustify(1, 1);
        settextstyle(1, 0, 5);
        setcolor(RGB(negative_color.red, negative_color.green,
                     negative_color.blue));
        outtextxy(300, 50, "����� �����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 100, "������ ����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 310, "�����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        outtextxy(300, 200, "���� � �����");
        outtextxy(300, 230, "� �������� ���������");
        outtextxy(300, 260, "��� ������ ���� � �����");
        InputBox(100, 120, 0, options.file_directory);
        button = getch();
        switch (button) {
        case 72:
            if (point > 1) {
                point--;
            };
            break;
        case 80:
            if (point < 2) {
                point++;
            };
            break;
        case 13:
            switch (point) {
            case 1:
                if (InputBox(100, 120, 1, options.file_directory))
                    ;
                break;
            case 2:
                ChangeBatDirectory();
                return;
            };
            break;
        case 27:
            return;
        };
    } while (1);
}

//��������� ������ � ����������, ����� ��������� ���������
int TempColor() {
    setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
    setlinestyle(0, 0, 3);
    rectangle(390, 120, 580, 260);
    setlinestyle(0, 0, 2);
    settextjustify(0, 0);
    settextstyle(1, 0, 1);
    rectangle(350, 300, 375, 325);
    rectangle(385, 300, 410, 325);
    outtextxy(420, 325, "����� �����");
    rectangle(350, 270, 375, 295);
    outtextxy(385, 295, "����");
    rectangle(455, 270, 480, 295);
    outtextxy(490, 295, "�������");
    setlinestyle(0, 0, 1);
    line(362, 275, 362, 290);
    line(362, 275, 365, 278);
    line(362, 275, 359, 278);
    line(467, 275, 467, 290);
    line(464, 287, 467, 290);
    line(470, 287, 467, 290);
    line(355, 312, 370, 312);
    line(355, 312, 358, 309);
    line(355, 312, 358, 315);
    line(390, 312, 405, 312);
    line(405, 312, 402, 309);
    line(405, 312, 402, 315);
    setlinestyle(0, 0, 3);
    settextjustify(0, 1);
    settextstyle(1, 0, 3);
    int point_color = 1, button;
    do {
        setfillstyle(1, RGB(0, 0, temp_color.blue));
        bar(520, 150, 570, 180);
        setfillstyle(1, RGB(temp_color.red, 0, 0));
        bar(400, 150, 450, 180);
        setfillstyle(1, RGB(0, temp_color.green, 0));
        bar(460, 150, 510, 180);
        setfillstyle(1, RGB(temp_color.red, temp_color.green, temp_color.blue));
        bar(400, 200, 570, 250);
        printf("red=%d  green=%d  blue=%d\n", temp_color.red, temp_color.green,
               temp_color.blue);
        setcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));
        if (point_color == 1) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        line(425, 145, 410, 135);
        line(425, 145, 440, 135);
        line(410, 135, 440, 135);
        setcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));
        if (point_color == 2) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        line(485, 145, 470, 135);
        line(485, 145, 500, 135);
        line(470, 135, 500, 135);
        setcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));
        if (point_color == 3) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        line(545, 145, 530, 135);
        line(545, 145, 560, 135);
        line(530, 135, 560, 135);
        switch (point_color) {
        case 1:
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            setfillstyle(1, RGB(bg_color.red, bg_color.green, bg_color.blue));
            bar(100, 20, 500, 80);
            outtextxy(300, 40, "�������������");
            outtextxy(300, 70, "��������");
            button = getch();
            switch (button) {
            case 80:
                if (temp_color.red > 20) {
                    temp_color.red -= 5;
                } else {
                    temp_color.red = 0;
                };
                break;
            case 72:
                if (temp_color.red == 0) {
                    temp_color.red += 20;
                } else if (temp_color.red < 255) {
                    temp_color.red += 5;
                } else {
                    temp_color.red = 255;
                };
                break;
            case 75:
                if (point_color > 1) {
                    point_color--;
                };
                break;
            case 77:
                if (point_color < 3) {
                    point_color++;
                };
                break;
            case 13:
                return 1;
            case 27:
                return 0;
            }
            break;
        case 2:
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            setfillstyle(1, RGB(bg_color.red, bg_color.green, bg_color.blue));
            bar(100, 20, 500, 80);
            outtextxy(300, 40, "�������������");
            outtextxy(300, 70, "�������");
            button = getch();
            switch (button) {
            case 75:
                if (point_color > 1) {
                    point_color--;
                };
                break;
            case 77:
                if (point_color < 3) {
                    point_color++;
                };
                break;
            case 80:
                if (temp_color.green > 20) {
                    temp_color.green -= 5;
                } else {
                    temp_color.green = 0;
                };
                break;
            case 72:
                if (temp_color.green == 0) {
                    temp_color.green += 20;
                } else if (temp_color.green < 255) {
                    temp_color.green += 5;
                } else {
                    temp_color.green = 255;
                };
                break;
            case 13:
                return 1;
            case 27:
                return 0;
            };
            break;
        case 3:
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            setfillstyle(1, RGB(bg_color.red, bg_color.green, bg_color.blue));
            bar(100, 20, 500, 80);
            outtextxy(300, 40, "�������������");
            outtextxy(300, 70, "������");
            button = getch();
            switch (button) {
            case 75:
                if (point_color > 1) {
                    point_color--;
                };
                break;
            case 77:
                if (point_color < 3) {
                    point_color++;
                };
                break;
            case 80:
                if (temp_color.blue > 20) {
                    temp_color.blue -= 5;
                } else {
                    temp_color.blue = 0;
                };
                break;
            case 72:
                if (temp_color.blue == 0) {
                    temp_color.blue += 20;
                } else if (temp_color.blue < 255) {
                    temp_color.blue += 5;
                } else {
                    temp_color.blue = 255;
                };
                break;
            case 13:
                return 1;
            case 27:
                return 0;
            };
            break;
        };
    } while (1);
}

//������� ���������� ������ ����� � ����� ��������������� �������
int pow(int x, int stepen) {
    for (int i = 2; i <= stepen; i++) x = x * x;
    if (stepen == 0)
        return 1;
    return x;
}

//���� ������� �������� ���� ���������� �� ��������� �����
int ThemeInit(char* file_name) {
    FILE* theme_file;
    int i, j, symbol, point = 1;
    int color[4][4];

    if ((theme_file = fopen(file_name, "r")) == NULL)
        return 0;
    while (symbol != '*') {
        symbol = fgetc(theme_file);
        if (symbol == EOF) {
            printf("���� � ����� �������� �����������");
            return 0;
        };
    };
    rewind(theme_file);
    while (point < 6) {
        for (i = 0; i <= 3; i++) {
            for (j = 0; j <= 3; j++) {
                color[i][j] = 0;
            };
        };
        i = 1;
        j = 0;
        while (symbol != ':') {
            symbol = fgetc(theme_file);
            if ((symbol == ' ') || (symbol == ':')) {
                color[i][0] = j;
                i++;
                j = 0;
            };
            if ((symbol >= 48) && (symbol <= 57)) {
                j++;
                color[i][j] = symbol - 48;
            };
        };
        temp_color.red = color[1][1] * pow(10, color[1][0] - 1) +
                         color[1][2] * pow(10, color[1][0] - 2) +
                         color[1][3] * pow(10, color[1][0] - 3);
        temp_color.green = color[2][1] * pow(10, color[2][0] - 1) +
                           color[2][2] * pow(10, color[2][0] - 2) +
                           color[2][3] * pow(10, color[2][0] - 3);
        temp_color.blue = color[3][1] * pow(10, color[3][0] - 1) +
                          color[3][2] * pow(10, color[3][0] - 2) +
                          color[3][3] * pow(10, color[3][0] - 3);
        printf("%d) red=%d  green=%d  blue=%d\n", point, temp_color.red,
               temp_color.green, temp_color.blue);
        switch (point) {
        case 1:
            bg_color.red = temp_color.red;
            bg_color.blue = temp_color.blue;
            bg_color.green = temp_color.green;
            break;
        case 2:
            point_color.red = temp_color.red;
            point_color.green = temp_color.green;
            point_color.blue = temp_color.blue;
            break;
        case 3:
            punkt_color.red = temp_color.red;
            punkt_color.green = temp_color.green;
            punkt_color.blue = temp_color.blue;
            break;
        case 4:
            word_color.red = temp_color.red;
            word_color.blue = temp_color.blue;
            word_color.green = temp_color.green;
            break;
        case 5:
            negative_color.red = temp_color.red;
            negative_color.blue = temp_color.blue;
            negative_color.green = temp_color.green;
            break;
        };
        while (symbol != 10) symbol = fgetc(theme_file);
        point++;
    };
    printf("\n***\n");
    fclose(theme_file);
    return 1;
}

//��������� �������� ����, ����� ������� ��������� �� ColorThemes
//�������� ������������ ����������� ������ ������� ThemeInit, ������� ���������
//���� � ����� ����
void Themes(int point) {
    switch (point) {
    case 1:
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (!(ThemeInit("..\\themes\\�����������.txt"))) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            outtextxy(300, 70, "�� ���������");
        };
        outtextxy(300, 40, "�����������");
        break;
    case 2:
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (!(ThemeInit("..\\themes\\������������ ������.txt"))) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            outtextxy(300, 70, "�� ���������");
        };
        outtextxy(300, 40, "������������ ������");
        break;
    case 3:
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (!(ThemeInit("..\\themes\\���.txt"))) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            outtextxy(300, 70, "�� ���������");
        };
        outtextxy(300, 40, "���");
        break;
    case 4:
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (!(ThemeInit("..\\themes\\����������.txt"))) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            outtextxy(300, 70, "�� ���������");
        };
        outtextxy(300, 40, "����������");
        break;
    case 5:
        if (!(ThemeInit("..\\themes\\׸���-����� �����.txt"))) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            outtextxy(300, 70, "�� ���������");
        };
        outtextxy(300, 40, "׸���-����� �����");
        break;
    case 6:
        if (!(ThemeInit("..\\themes\\����-������ �������.txt"))) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            outtextxy(300, 70, "�� ���������");
        };
        outtextxy(300, 40, "����-������ �������");
        break;
    case 7:
        if (!(ThemeInit("..\\themes\\������.txt"))) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
            outtextxy(300, 70, "�� ���������");
        };
        outtextxy(300, 40, "������");
        break;
    };
}

//���� ������ ����
void ColorThemes() {
    int point = 1, button;
    setlinestyle(0, 0, 3);
    do {
        Themes(point);
        setbkcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));
        cleardevice();
        Themes(point);
        line(0, 70, 600, 70);
        settextjustify(1, 1);
        settextstyle(1, 0, 3);
        button = getch();
        switch (button) {
        case 75:
            if (point > 1) {
                point--;
            };
            break;
        case 77:
            if (point < 7) {
                point++;
            };
            break;
        case 72:
            if (point > 1) {
                point--;
            };
            break;
        case 80:
            if (point < 7) {
                point++;
            };
            break;
        case 13:
            return;
        case 27:
            Themes(1);
            cleardevice();
            Themes(1);
            return;
        };
    } while (1);
}

//���� ������ ��������� ����� ����������� ������ ������� TempColor
void ColorSettings() {
    int point = 1, button;
    setlinestyle(0, 0, 3);
    do {
        setbkcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));
        cleardevice();
        settextjustify(0, 1);
        settextstyle(1, 0, 3);
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(20, 100, "���");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(20, 140, "������ ����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(20, 180, "���������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(20, 220, "����������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 5) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(20, 260, "�������� �����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextjustify(1, 1);
        if (point == 6) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "�����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        button = getch();
        switch (button) {
        case 75:
            if (point > 1) {
                point--;
            };
            break;
        case 77:
            if (point < 6) {
                point++;
            };
            break;
        case 72:
            if (point > 1) {
                point--;
            };
            break;
        case 80:
            if (point < 6) {
                point++;
            };
            break;
        case 13:
            switch (point) {
            case 1:
                settextjustify(0, 1);
                setcolor(RGB(negative_color.red, negative_color.green,
                             negative_color.blue));
                outtextxy(20, 100, "���");
                setcolor(RGB(punkt_color.red, punkt_color.green,
                             punkt_color.blue));
                settextjustify(1, 1);
                temp_color.red = bg_color.red;
                temp_color.green = bg_color.green;
                temp_color.blue = bg_color.blue;
                if (TempColor()) {
                    bg_color.red = temp_color.red;
                    bg_color.green = temp_color.green;
                    bg_color.blue = temp_color.blue;
                };
                break;
            case 2:
                settextjustify(0, 1);
                setcolor(RGB(negative_color.red, negative_color.green,
                             negative_color.blue));
                outtextxy(20, 140, "������ ����");
                setcolor(RGB(punkt_color.red, punkt_color.green,
                             punkt_color.blue));
                settextjustify(1, 1);
                temp_color.red = punkt_color.red;
                temp_color.green = punkt_color.green;
                temp_color.blue = punkt_color.blue;
                if (TempColor()) {
                    punkt_color.red = temp_color.red;
                    punkt_color.green = temp_color.green;
                    punkt_color.blue = temp_color.blue;
                };
                break;
            case 3:
                settextjustify(0, 1);
                setcolor(RGB(negative_color.red, negative_color.green,
                             negative_color.blue));
                outtextxy(20, 180, "���������");
                setcolor(RGB(punkt_color.red, punkt_color.green,
                             punkt_color.blue));
                settextjustify(1, 1);
                temp_color.red = point_color.red;
                temp_color.green = point_color.green;
                temp_color.blue = point_color.blue;
                if (TempColor()) {
                    point_color.red = temp_color.red;
                    point_color.green = temp_color.green;
                    point_color.blue = temp_color.blue;
                };
                break;
            case 4:
                settextjustify(0, 1);
                setcolor(RGB(negative_color.red, negative_color.green,
                             negative_color.blue));
                outtextxy(20, 220, "����������");
                setcolor(RGB(punkt_color.red, punkt_color.green,
                             punkt_color.blue));
                settextjustify(1, 1);
                temp_color.red = negative_color.red;
                temp_color.green = negative_color.green;
                temp_color.blue = negative_color.blue;
                if (TempColor()) {
                    negative_color.red = temp_color.red;
                    negative_color.green = temp_color.green;
                    negative_color.blue = temp_color.blue;
                };
                break;
            case 5:
                settextjustify(0, 1);
                setcolor(RGB(negative_color.red, negative_color.green,
                             negative_color.blue));
                outtextxy(20, 260, "�������� �����");
                setcolor(RGB(punkt_color.red, punkt_color.green,
                             punkt_color.blue));
                settextjustify(1, 1);
                temp_color.red = word_color.red;
                temp_color.green = word_color.green;
                temp_color.blue = word_color.blue;
                if (TempColor()) {
                    word_color.red = temp_color.red;
                    word_color.green = temp_color.green;
                    word_color.blue = temp_color.blue;
                };
                break;
            case 6:
                return;
            };
            break;
        case 27:
            return;
        };
    } while (1);
}

// ��������� ����������
void Design() {
    cleardevice();
    int point = 1, button;
    settextjustify(1, 1);
    do {
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 100, "������� ���� ����������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 130, "��������� ����� �������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "�����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        button = getch();
        switch (button) {
        case 72:
            if (point > 1) {
                point--;
            };
            break;
        case 80:
            if (point < 3) {
                point++;
            };
            break;
        case 13:
            switch (point) {
            case 1:
                ColorThemes();
                return;
            case 2:
                ColorSettings();
                return;
            case 3:
                return;
            };
        case 27:
            return;
        };
    } while (1);
}

//���� ��������
void Options() {
    int button, point = 1;
    cleardevice();
    settextstyle(1, 0, 3);
    settextjustify(1, 1);
    printf("���������:\n");
    printf("������� ����: %s \n", options.input_file_name);
    printf("�������� ����: %s \n", options.output_file_name);
    printf("���� � �����: %s \n", options.cache_file_name);
    printf("������� � �������: %s \n", options.file_directory);
    printf("������� ��������: %d \n", options.console_on);

    do {
        cleardevice();
        settextstyle(1, 0, 6);
        setcolor(RGB(negative_color.red, negative_color.green,
                     negative_color.blue));
        outtextxy(300, 100, "��������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        outtextxy(300, 180, "���������:");
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 220, "�������� ������� �����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 250, "��������� ����������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 280, "�������� ���������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        if (options.console_on) {
            outtextxy(300, 310, "�� ���������� �������");
        } else {
            outtextxy(300, 310, "���������� ���������� �������");
        };
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 5) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 340, "�����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
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
                InputPathWindow();
                return;
            case 2:
                Design();
                return;
            case 3:
                RestoreOptionsWindow();
                return;
            case 4:
                if (options.console_on) {
                    options.console_on = 0;
                    FreeConsole();
                } else {
                    options.console_on = 1;
                    AllocConsole();
                };
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
