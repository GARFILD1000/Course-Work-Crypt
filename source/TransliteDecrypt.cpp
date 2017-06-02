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

//������� ����������� ������� ��������
//���������� 1, ���� ��������� ���� �� ��������
//���������� 2, ���� ���� � ����������� �������� �� ��������
//���������� 4, ���� ����� ���� ������ ���������
//���������� 5, ���� ����������� ������ �������
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
            case 'f': ch = '�'; break;
        	case ',': ch = '�'; break;
        	case 'd': ch = '�'; break;
            case 'u': ch = '�'; break;
            case 'l': ch = '�'; break;
            case 't': ch = '�'; break;
            case '`': ch = '�'; break;
            case ';': ch = '�'; break;
            case 'p': ch = '�'; break;
            case 'b': ch = '�'; break;
            case 'q': ch = '�'; break;
            case 'r': ch = '�'; break;
            case 'k': ch = '�'; break;
            case 'v': ch = '�'; break;
            case 'y': ch = '�'; break;
        	case 'j': ch = '�'; break;
            case 'g': ch = '�'; break;
            case 'h': ch = '�'; break;
            case '�': ch = '�'; break;
            case 'n': ch = '�'; break;
            case 'e': ch = '�'; break;
            case 'a': ch = '�'; break;
            case '[': ch = '�'; break;
            case 'w': ch = '�'; break;
            case 'x': ch = '�'; break;
            case 'i': ch = '�'; break;
            case 'o': ch = '�'; break;
            case ']': ch = '�'; break;
            case 's': ch = '�'; break;
            case 'm': ch = '�'; break;
            case 39: ch = '�'; break;
            case '.': ch = '�'; break;
            case 'z': ch = '�'; break;
            case 'F': ch = '�'; break;
            case '<': ch = '�'; break;
            case 'D': ch = '�'; break;
            case 'U': ch = '�'; break;
            case 'L': ch = '�'; break;
            case 'T': ch = '�'; break;
            case '~': ch = '�'; break;
            case ':': ch = '�'; break;
            case 'P': ch = '�'; break;
            case 'B': ch = '�'; break;
            case 'Q': ch = '�'; break;
            case 'R': ch = '�'; break;
            case 'K': ch = '�'; break;
            case 'V': ch = '�'; break;
            case 'Y': ch = '�'; break;
            case 'J': ch = '�'; break;
            case 'G': ch = '�'; break;
            case 'H': ch = '�'; break;
            case 'C': ch = '�'; break;
            case 'N': ch = '�'; break;
            case 'E': ch = '�'; break;
            case 'A': ch = '�'; break;
            case '{': ch = '�'; break;
            case 'W': ch = '�'; break;
            case 'X': ch = '�'; break;
            case 'I': ch = '�'; break;
            case 'O': ch = '�'; break;
            case '}': ch = '�'; break;
            case 'S': ch = '�'; break;
            case 'M': ch = '�'; break;
            case '"': ch = '�'; break;
            case '>': ch = '�'; break;
            case 'Z': ch = '�'; break;
		}
    	putc(ch,fp2);                    
    }
    fclose (fp1);
    fclose (fp2);
    return 5;
}

//���� ����������� ������� ��������
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
        outtextxy(300, 340, "������������!");
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
