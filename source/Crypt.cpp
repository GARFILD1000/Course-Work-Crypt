#include <conio.h>
#include <graphics.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <iostream>

#include "Struct.h"
#include "Options.h"
#include "InputBox.h"
#include "CezarCrypt.h"
#include "CezarDecrypt.h"
#include "VigenereCrypt.h"
#include "VigenereDecrypt.h"
#include "SaveRestore.h"

struct Options options;
struct Color bg_color, point_color, punkt_color, word_color, temp_color,
        negative_color;

int MenuDecryptCategory() {
    int button, point = 1;
    setcolor(15);
    do {
        cleardevice();
        settextstyle(1, 0, 6);
        setcolor(RGB(negative_color.red, negative_color.green,
                     negative_color.blue));
        outtextxy(300, 100, "ШИФРАТОР");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        outtextxy(300, 180, "ВЫБОР РАСШИФРОВКИ:");
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 220, "Цезаря");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 250, "Виженера");
        /*setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3)
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,280,"");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==4)
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,310,"");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==5)
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,340,"");*/
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "Назад");
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
            if (point != 3)
                switch (point) {
                case 1:
                    printf("Расшифровка Цезаря");
                    CezarDecryptWindow();
                    break;
                case 2:
                    printf("Расшифровка Виженера");
                    VigenereDecryptWindow();
                    break;
                case 3:
                    break;
                };
            cleardevice();
            return 0;
        case 27:
            cleardevice();
            return 0;
        };
    } while (1);
}

//подменю зашифровки
int MenuCryptCategory() {
    int button, point = 1;
    do {
        cleardevice();
        settextstyle(1, 0, 6);
        setcolor(RGB(negative_color.red, negative_color.green,
                     negative_color.blue));
        outtextxy(300, 100, "ШИФРАТОР");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        outtextxy(300, 180, "ВЫБОР ШИФРОВКИ:");
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 220, "Цезаря");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 250, "Виженера");
        /*setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3)
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,280,"");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==4)
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,310,"");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==5)
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,340,"");*/
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 370, "Назад");
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

            if (point != 3) {
                switch (point) {
                case 1:
                    printf("Шифровка Цезаря");
                    CezarCryptWindow();
                    break;
                case 2:
                    printf("Шифровка Виженера");
                    VigenereCryptWindow();
                    break;
                case 3:
                    break;
                };
            };
            cleardevice();
            return 0;
        case 27:
            cleardevice();
            return 0;
        };
    } while (1);
}

int MainMenu() {
    int button, point = 1, red = 0;
    settextstyle(1, 0, 3);
    settextjustify(1, 1);
    setbkcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));
    do {
        cleardevice();
        settextstyle(1, 0, 6);
        if (red < 250)
            red++;
        setcolor(RGB(negative_color.red, negative_color.green,
                     negative_color.blue));
        outtextxy(300, 100, "ШИФРАТОР");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        settextstyle(1, 0, 3);
        outtextxy(300, 180, "ГЛАВНОЕ МЕНЮ:");
        if (point == 1) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 250, "Зашифровать");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 2) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 280, "Расшифровать");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 3) {
            setcolor(RGB(point_color.red, point_color.green, point_color.blue));
        };
        outtextxy(300, 310, "Настройки");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
        if (point == 4) {
            setcolor(RGB(negative_color.red, negative_color.green,
                         negative_color.blue));
        };
        outtextxy(300, 340, "Выход");
        setcolor(RGB(punkt_color.red, punkt_color.green, punkt_color.blue));
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
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 0;
            };
        case 27:
            return 0;
        };
        Sleep(10);
    } while (1);
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    LoadOptions();
    
    if (!options.console_on) {
    //    FreeConsole();
    };

    initwindow(600, 400, "Шифратор");

    setbkcolor(RGB(bg_color.red, bg_color.green, bg_color.blue));

    cleardevice();
//класс координат точки    
    POINT mypoint;
//находится точка дисплея, где расположится окно
    mypoint.x = getmaxwidth() / 2 - 300;
    mypoint.y = getmaxheight() / 2 - 200;
//переменной дескриптора HWND передаётся дескриптор окна с заданным названием
    HWND BGI_window = FindWindow(NULL, "Шифратор");
//окно ставится по центру    
    MoveWindow(BGI_window, mypoint.x, mypoint.y, 608, 423, false);
    
    int menu_choice;
    do {
        menu_choice = MainMenu();
        switch (menu_choice) {
        case 1:
            MenuCryptCategory();
            break;
        case 2:
            MenuDecryptCategory();
            break;
        case 3:
            Options();
            break;
        case 0:
            return 0;
        };
        SaveOptions();
    } while (1);
}
