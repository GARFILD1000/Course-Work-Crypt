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

//������� �������� ������� ������
//�� ���� �������� �������� ������ �� ��������
//���������� 1, ���� ��������� ���� �� ��������
//���������� 2, ���� ���� � ����������� �������� �� ��������
//���������� 4, ���� ����� ���� ������ ���������
//���������� 0, ���� �������� ������ �������
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
	
    while (!feof(fp1)){
    	ch = getc(fp1);                      
    	switch (ch){
            case '�': ch = 'f'; break;
        	case '�': ch = ','; break;
        	case '�': ch = 'd'; break;
            case '�': ch = 'u'; break;
            case '�': ch = 'l'; break;
            case '�': ch = 't'; break;
            case '�': ch = '`'; break;
            case '�': ch = ';'; break;
            case '�': ch = 'p'; break;
            case '�': ch = 'b'; break;
            case '�': ch = 'q'; break;
            case '�': ch = 'r'; break;
            case '�': ch = 'k'; break;
            case '�': ch = 'v'; break;
            case '�': ch = 'y'; break;
        	case '�': ch = 'j'; break;
            case '�': ch = 'g'; break;
            case '�': ch = 'h'; break;
            case '�': ch = 'c'; break;
            case '�': ch = 'n'; break;
            case '�': ch = 'e'; break;
            case '�': ch = 'a'; break;
            case '�': ch = '['; break;
            case '�': ch = 'w'; break;
            case '�': ch = 'x'; break;
            case '�': ch = 'i'; break;
            case '�': ch = 'o'; break;
            case '�': ch = ']'; break;
            case '�': ch = 's'; break;
            case '�': ch = 'm'; break;
            case '�': ch = 39; break;
            case '�': ch = '.'; break;
            case '�': ch = 'z'; break;
            case '�': ch = 'F'; break;
            case '�': ch = '<'; break;
            case '�': ch = 'D'; break;
            case '�': ch = 'U'; break;
            case '�': ch = 'L'; break;
            case '�': ch = 'T'; break;
            case '�': ch = '~'; break;
            case '�': ch = ':'; break;
            case '�': ch = 'P'; break;
            case '�': ch = 'B'; break;
            case '�': ch = 'Q'; break;
            case '�': ch = 'R'; break;
            case '�': ch = 'K'; break;
            case '�': ch = 'V'; break;
            case '�': ch = 'Y'; break;
            case '�': ch = 'J'; break;
            case '�': ch = 'G'; break;
            case '�': ch = 'H'; break;
            case '�': ch = 'C'; break;
            case '�': ch = 'N'; break;
            case '�': ch = 'E'; break;
            case '�': ch = 'A'; break;
            case '�': ch = '{'; break;
            case '�': ch = 'W'; break;
            case '�': ch = 'X'; break;
            case '�': ch = 'I'; break;
            case '�': ch = 'O'; break;
            case '�': ch = '}'; break;
            case '�': ch = 'S'; break;
            case '�': ch = 'M'; break;
            case '�': ch = '"'; break;
            case '�': ch = '>'; break;
            case '�': ch = 'Z'; break;
		}
	    putc(ch,fp2);                    
    }
    fclose (fp1);
    fclose (fp2);
    return 0;
}

//���� ���������� ������� ������
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
        outtextxy(300, 50, "���� ��������");
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
        outtextxy(300, 340, "�����������!");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "�����");
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

