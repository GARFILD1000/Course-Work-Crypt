


void TempColor(){          //заполнение временной структуры RGB параметрами цвета
     setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
     setlinestyle(0,0,3);
     rectangle(390,120,580,260);
     setlinestyle(0,0,2);
     settextjustify(0,0);
     settextstyle(1,0,1);
     rectangle(350, 300, 375, 325);
     rectangle(385, 300, 410, 325);
     
     outtextxy(420,325,"Выбор цвета");
     rectangle(350, 270, 375, 295);
     outtextxy(385,295,"Ярче");
     rectangle(455, 270, 480, 295);
     outtextxy(490,295,"Тусклее");
     setlinestyle(0,0,1);
     
     line(362,275,362,290);
     line(362,275,365,278);
     line(362,275,359,278);
     
     line(467,275,467,290);
     line(464,287,467,290);
     line(470,287,467,290);
     
     line(355,312,370,312);
     line(355,312,358,309);
     line(355,312,358,315);
     
     line(390,312,405,312);
     line(405,312,402,309);
     line(405,312,402,315);
     
     setlinestyle(0,0,2);
     settextjustify(0,1);
     settextstyle(1,0,3);
     int point_color =1, button;
     do{ 
         setfillstyle(1,RGB(0,0,temp_color.blue));    
         bar(520,150,570,180);     
         setfillstyle(1,RGB(temp_color.red,0,0));    
         bar(400,150,450,180);
         setfillstyle(1,RGB(0,temp_color.green,0));    
         bar(460,150,510,180);
         setfillstyle(1,RGB(temp_color.red,temp_color.green,temp_color.blue));
         bar(400,200,570,250);
         
         printf("red=%d  green=%d  blue=%d\n",temp_color.red,temp_color.green,temp_color.blue);
         
         setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue));
         if(point_color==1)
         setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
         line(425,145,410,135);
         line(425,145,440,135);
         line(410,135,440,135);
         setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue));
         if(point_color==2)
         setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
         line(485,145,470,135);
         line(485,145,500,135);
         line(470,135,500,135);
         setcolor(RGB(bg_color.red,bg_color.green,bg_color.blue));
         if(point_color==3)
         setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
         line(545,145,530,135);
         line(545,145,560,135);
         line(530,135,560,135);
         
         switch(point_color){
                             
         case 1:                       
         setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
         setfillstyle(1,RGB(bg_color.red,bg_color.green,bg_color.blue));
         bar(100,20,500,80);
         outtextxy(300,40,"Интенсивность");
         outtextxy(300,70,"красного");
         button=getch();
         switch(button){
         case 80: if (temp_color.red>20) temp_color.red-=5; else temp_color.red=0; break;
         case 72: if (temp_color.red==0) temp_color.red+=20; else if (temp_color.red<255) temp_color.red+=5; else temp_color.red=255; break;
         case 75: if (point_color>1) point_color--; break;
         case 77: if (point_color<3) point_color++; break;
         }                        
         break;
                               
         case 2:                  
         setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
         setfillstyle(1,RGB(bg_color.red,bg_color.green,bg_color.blue));
         bar(100,20,500,80);
         outtextxy(300,40,"Интенсивность");
         outtextxy(300,70,"зелёного");
         button=getch();
         switch(button){
         case 75: if (point_color>1) point_color--; break;
         case 77: if (point_color<3) point_color++; break;
         case 80: if (temp_color.green>20) temp_color.green-=5; else temp_color.green=0; break;
         case 72: if (temp_color.green==0) temp_color.green+=20; else if (temp_color.green<255) temp_color.green+=5; else temp_color.green=255; break;
         };                      
         break;
                               
         case 3:                      
         setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
         setfillstyle(1,RGB(bg_color.red,bg_color.green,bg_color.blue));
         bar(100,20,500,80);
         outtextxy(300,40,"Интенсивность");
         outtextxy(300,70,"синего");
         button=getch();
         switch(button){
         case 75: if (point_color>1) point_color--; break;
         case 77: if (point_color<3) point_color++; break;
         case 80: if (temp_color.blue>20) temp_color.blue-=5; else temp_color.blue=0; break;
         case 72: if (temp_color.blue==0) temp_color.blue+=20; else if (temp_color.blue<255) temp_color.blue+=5; else temp_color.blue=255; break;
         };                      
         break;
         
         };
     }while(button!=13);
}

void ColorSettings(){          //кастомная настройка цветов, изменение цветов в структурах через временную структуру 
    int point=1, button;
    setlinestyle(0,0,3);
    do{ 
        setbkcolor(RGB(bg_color.red,bg_color.green,bg_color.blue));
        cleardevice(); 
        settextjustify(0,1);
        settextstyle(1,0,3);
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if(point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(20,100,"Фон"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));  
        if(point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(20,140,"Пункты меню");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if(point==3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(20,180,"Выделение");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if(point==4) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(20,220,"Негативное");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if(point==5) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(20,260,"Заполнение слова");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextjustify(1,1);
        if(point==6) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,370,"Назад");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        temp_color.red=temp_color.green=temp_color.blue=rand()%255;
        
        button=getch();
        switch(button){
                      case 75: if (point>1) point--; break;
                      case 77: if (point<6) point++; break;
                      case 72: if (point>1) point--; break;
                      case 80: if (point<6) point++; break;
                      case 13: 
                               switch(point){
                               case 1:
                                   settextjustify(0,1);
                                   setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
                                   outtextxy(20,100,"Фон"); 
                                   setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
                                   settextjustify(1,1);
                                   TempColor();
                                   bg_color.red = temp_color.red;
                                   bg_color.green = temp_color.green;
                                   bg_color.blue = temp_color.blue;                               
                               break;     
                               case 2:
                                   settextjustify(0,1);
                                   setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue)); 
                                   outtextxy(20,140,"Пункты меню"); 
                                   setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
                                   settextjustify(1,1);
                                   TempColor();
                                   punkt_color.red = temp_color.red;
                                   punkt_color.green = temp_color.green;
                                   punkt_color.blue = temp_color.blue;   
                               break;    
                               case 3:
                                   settextjustify(0,1);
                                   setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue)); 
                                   outtextxy(20,180,"Выделение"); 
                                   setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
                                   settextjustify(1,1);
                                   TempColor();
                                   point_color.red = temp_color.red;
                                   point_color.green = temp_color.green;
                                   point_color.blue = temp_color.blue;   
                               break;
                               case 4:
                                   settextjustify(0,1);
                                   setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue)); 
                                   outtextxy(20,220,"Негативное");
                                   setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
                                   settextjustify(1,1);
                                   TempColor();
                                   negative_color.red = temp_color.red;
                                   negative_color.green = temp_color.green;
                                   negative_color.blue = temp_color.blue; 
                               break;
                               case 5:
                                   settextjustify(0,1);
                                   setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue)); 
                                   outtextxy(20,260,"Заполнение слова");
                                   setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
                                   settextjustify(1,1);
                                   TempColor();
                                   word_color.red = temp_color.red;
                                   word_color.green = temp_color.green;
                                   word_color.blue = temp_color.blue; 
                               break;
                               case 6:
                                   return;
                               break;
                               };
                      break;
                      case 27: return;
        };
    }while(1);
}


int Design(){  // Настройка оформления
    cleardevice();
    int point=1, button;
    
    settextjustify(1,1);
    do{
    setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));         
    if(point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
    outtextxy(300,100,"Темы (в разработке)"); 
    setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
    if(point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
    outtextxy(300,130,"Настроить цвета вручную");
    setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
    if(point==3) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,370,"Назад");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button=getch();
        switch(button){
                      case 72: if (point>1) point--; break;
                      case 80: if (point<3) point++; break;
                      case 13: switch(point){
                               case 1: break;
                               case 2: ColorSettings(); return 0; break;
                               case 3: return 0; break;
                      case 27:  return 0;
                               };
        };                       
        
    }while(1);
    
    
    
    
}




int Options(){    //Меню настроек
int button, point=1;
cleardevice();
settextstyle(1,0,3);
settextjustify(1,1);

    do{ settextstyle(1,0,6);
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,100,"ШИФРАТОР"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextstyle(1,0,3);   
        outtextxy(300,180,"НАСТРОЙКИ:");    
        if (point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,220,"Разное (в разработке)");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,250,"Настроить оформление");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,340,"Назад");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button=getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<5) point++; break;
        case 13: 
             switch(point){
             case 1: 
                  cleardevice();
                  return 0;
             case 2: 
                 
                 Design();
                 
                 cleardevice();
                 return 0;
             case 3: cleardevice(); return 0;      
                          
             }; break;
        case 27: cleardevice(); return 0;
        };
    } while(1);  
  
};
