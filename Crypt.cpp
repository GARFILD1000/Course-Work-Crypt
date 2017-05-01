#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <time.h>
#include <windows.h>


struct options{
    char* input_file_name;
    char* output_file_name;
};
struct options options;

#include "VigenereCrypt.cpp"

struct color{              //структуры цвета, хранят RGB-значения каждого цвета
    int red;
    int green;
    int blue;
};
struct color bg_color, point_color, punkt_color, word_color, temp_color, negative_color;


int MenuCategory(){              //подменю зашифровки
    int key[2]={1,-1};             //массив ключей, -1 даёт знать, что это конец массива
    int button, point=1;
    setcolor(15);
    do{
        cleardevice();
        settextstyle(1,0,6);
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,100,"ШИФРАТОР"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextstyle(1,0,3); 
        outtextxy(300,180,"ВЫБОР ШИФРОВКИ:");
        if (point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,220,"Цезаря (в разработке)");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,250,"Виженера");
        /*setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,280,"");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==4) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,310,"");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==5) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,340,"");*/
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,370,"Назад");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button=getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<3) point++; break;
        case 13: 
            
            if (point!=3) 
                switch(point){
                case 1: /* Точка вызова функции шифра цезаря*/ ; break;
                case 2:  VigenereCrypt(key); break;
                case 3: break;
                };
            cleardevice(); 
            return 0;       
        case 27: cleardevice(); return 0;
        };
    } while(1);      
    
    
    
};


int MainMenu(){
int button, point=1, red=0;
settextstyle(1,0,3);
settextjustify(1,1);
    do{ settextstyle(1,0,6);
        if (red <250) red++;
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,100,"ШИФРАТОР"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue)); 
        settextstyle(1,0,3);   
        outtextxy(300,180,"ГЛАВНОЕ МЕНЮ:");    
        if (point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,250,"Зашифровать");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,280,"Прочее...");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,310,"Настройки");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==4) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,340,"Выход");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button=getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<4) point++; break;
        case 13: 
             switch(point){
             case 1: return 1;
             case 2: return 2;
             case 3: return 3;
             case 4: return 0;     
             }; 
        case 27: return 0;
        };
        Sleep(10);
    } while(1);  
  
    
}



int main(){
    srand(time(NULL));
    setlocale(LC_ALL,"rus");  
    
    punkt_color.blue=200;
    punkt_color.green=200;
    punkt_color.red=200;
    
    point_color.blue=200;
    point_color.green=0;
    point_color.red=0;
    
    bg_color.red=0;
    bg_color.blue=0;
    bg_color.green=0;
    
    negative_color.red=200;
    negative_color.blue=0;
    negative_color.green=0;
    
    options.input_file_name="input.txt";
    options.output_file_name="output.txt";
    
    //FreeConsole();
    initwindow(600,400,"Шифратор");
    
    setbkcolor(RGB(bg_color.red,bg_color.green,bg_color.blue));
    
    cleardevice();
   
    POINT mypoint;                //класс координат точки
    mypoint.x=getmaxwidth()/2-300; mypoint.y=getmaxheight()/2-200;   //находится точка дисплея, где расположится окно
    HWND BGI_window = WindowFromPoint (mypoint);            // переменной дескриптора HWND передаётся дескриптор окна в заданной точке
    MoveWindow(BGI_window,mypoint.x,mypoint.y,608,423,false);  //окно ставится по центру
    
    int menu_choice;
    do{
        menu_choice=MainMenu();
        switch (menu_choice){
        case 1: MenuCategory(); break;
        case 2: break;
        case 3: break;
        case 0: return 0;       
        };       
    }while(1);
}
