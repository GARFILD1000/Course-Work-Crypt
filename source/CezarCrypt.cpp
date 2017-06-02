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

//�������, � ������� ������� ����� ������ �������� num
//��������� �� ���������
//��������� x � y - ���������� ������ �������� ���� �������
int SetNumberBox(int x, int y, int active, int &num) {
    char *num_out;
    int button;
    num_out = new char[10];
    setlinestyle(0, 0, 2);
    settextstyle(3, 0, 2);
    settextjustify(1, 0);
    setfillstyle(0, RGB(bg_color.red, bg_color.green, bg_color.blue));

    if (active) {
        setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        line(x, y + 20, x + 20, y + 5);
        line(x, y + 20, x + 20, y + 35);
        line(x + 20, y + 5, x + 20, y + 35);
        line(100 + x, y + 20, 80 + x, y + 5);
        line(100 + x, y + 20, 80 + x, y + 35);
        line(80 + x, y + 35, 80 + x, y + 5);
        do {
            bar(x + 25, y, x + 75, y + 40);
            itoa(num, num_out, 10);
            outtextxy(x + 50, y + 40, num_out);
            button = getch();
            switch (button) {
            case 77:
                num++;
                break;
            case 75:
                if (num > 0) {
                    num--;
                };
                break;
            case 13:
                return 1;
            case 27:
                return 0;
            };
        } while (1);
    } else {
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        itoa(num, num_out, 10);
        outtextxy(x + 50, y + 40, num_out);
        line(x, y + 20, x + 20, y + 5);
        line(x, y + 20, x + 20, y + 35);
        line(x + 20, y + 5, x + 20, y + 35);
        line(100 + x, y + 20, 80 + x, y + 5);
        line(100 + x, y + 20, 80 + x, y + 35);
        line(80 + x, y + 35, 80 + x, y + 5);
        return 0;
    };
}

//������� �������� ������� ������
//�� ���� �������� �������� ������ �� ��������
//���������� 1, ���� ��������� ���� �� ��������
//���������� 2, ���� ���� � ����������� �������� �� ��������
//���������� 4, ���� ����� ���� ������ ���������
//���������� 0, ���� �������� ������ �������
int CezarCrypt(int n) {
    setlocale(LC_ALL, "rus");
    FILE *fp1, *fp2;

    char *output_filename, *input_filename;

    input_filename = new char[150];
    output_filename = new char[150];
    StackString(options.file_directory, options.input_file_name,
                input_filename);
    StackString(options.file_directory, options.output_file_name,
                output_filename);
    printf("������� ���� %s\n", input_filename);
    printf("�������� ���� %s\n", output_filename);
    if (strcmp(input_filename, output_filename) == 0)
        return 4;
    printf("�������� �������� ����� ");
    if ((fp1 = fopen(input_filename, "r")) == NULL) {
        printf("�� ������!");
        return 1;
    };
    printf("���������\n");
    printf("�������� ��������� ����� ");
    if ((fp2 = fopen(output_filename, "w")) == NULL) {
        printf("�� ������!");
        return 2;
    };
    printf("���������\n");
    printf("�������� ��������...\n");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1)) {
        flag = 0;
        if (c >= 'A' && c <= 'Z') {
            c = c + (n % ENG);
            if (c > 'Z')
                c = 'A' + (c - 'Z') - 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z') {
            if ((c + (n % ENG)) > 'z')
                c = 'a' + ((c + (n % ENG)) - 'z') - 1;
            else
                c = c + (n % ENG);
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�') {
            c = c + (n % RUS);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�') {
            c = c + (n % RUS);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (!flag)
            fprintf(fp2, "%c", c);
        c = getc(fp1);
    }
    printf("�����������!\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}

//���� ���������� ������� ������
void CezarCryptWindow() {
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
        outtextxy(300, 50, "���� ������");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 100, "�������� �������� ����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 180, "�������� ������������� ����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 260, "������� ���� �����");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 340, "�����������!");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 5) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "�����");
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
                printf("����������� ���� �����\n");
                char *filelist_path;
                //����, � ������� ���������� ������ ������
                filelist_path = new char[150];
                StackString(options.file_directory, "filelist", filelist_path);
                CopyString(filelist_path, options.cache_file_name);
                //������ �������, ������� �������� ���� ������� ������
                ShellExecute(FindWindow(NULL, "��������"), "open",
                             "..\\binary\\MakeFileList.bat", NULL, NULL,
                             SW_HIDE);
                InputBox(100, 110, 1, options.input_file_name);
                remove(filelist_path);
                CopyString("..\\saves\\cache.txt", options.cache_file_name);
                printf("\n�������: ");
                printf("%s \n", input_filename);
                break;
            case 2:
                printf("����������� ���� �����\n");
                InputBox(100, 190, 1, options.output_file_name);
                printf("\n�������: ");
                printf("%s \n", output_filename);
                break;
            case 3:
                printf("������������ ������ SetNumber\n");
                SetNumberBox(250, 270, 1, num);
                printf("\n�������: ");
                printf("%d \n", num);
                break;
            case 4:
                int result;
                result = CezarCrypt(num);
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
