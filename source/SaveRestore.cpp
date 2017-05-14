void RestoreOptions();
void RestoreOptionsWindow();
void SaveOptions();
void LoadOptions();
//   процедура заполняет структуры с натройками стандартными значениями
void RestoreOptions(){
FILE *options_file;
    if ((options_file=fopen("..//saves//default.dat","rb"))==NULL)
        printf("Восстановление невозможно: нет файла default.dat \n");
    fread(&bg_color,sizeof(color),1,options_file);  
    fread(&point_color,sizeof(color),1,options_file);
    fread(&punkt_color,sizeof(color),1,options_file);  
    fread(&word_color,sizeof(color),1,options_file);  
    fread(&negative_color,sizeof(color),1,options_file);
    fread(&options,sizeof(options),1,options_file);
    fclose(options_file);
    return;
}

//процедура, отрисовывающая окно подтверждения сброса настроек 
void RestoreOptionsWindow(){
    int point=1, button; 
    do{ cleardevice();
        outtextxy(300,70,"СБРОСИТЬ");
        outtextxy(300,100,"НАСТРОЙКИ?");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==1) {
            outtextxy(300,250,"настройки и статистика");
            setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
            outtextxy(300,280,"сбросятся");
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        };
        outtextxy(300,160,"Да");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) {
            
            outtextxy(300,250,"настройки и статистика");
            outtextxy(300,280,"не сбросятся");
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        };
        outtextxy(300,190,"Нет");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button = getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<2) point++; break;
        case 13: RestoreOptions(); return;
        };
    }while(1);                                           
}

//   процедура загружает настройки и статистику из файла options.dat в соотвтствующие структуры
//   если этого файла нет в каталоге, создаёт его и заполняет изначальными значениями
void LoadOptions(){
    FILE *options_file;
    printf("Загрузка опций");
    if ((options_file=fopen("..//saves//options.dat","rb"))==NULL){
        printf(" прервана. \n");
        RestoreOptions();
        SaveOptions();
        printf("Загружены стандартные опции\n");
        return;
    };
    fread(&bg_color,sizeof(color),1,options_file);  
    fread(&point_color,sizeof(color),1,options_file);
    fread(&punkt_color,sizeof(color),1,options_file);  
    fread(&word_color,sizeof(color),1,options_file);  
    fread(&negative_color,sizeof(color),1,options_file);
    fread(&options,sizeof(options),1,options_file);
    fclose(options_file);
    printf(" завершена!\n");
    return;
}

// процедура сохраняет настройки и статистику в файл options.dat
void SaveOptions(){
    FILE *options_file;
    printf("Сохранение опций");
    options_file=fopen("..//saves//options.dat","wb");
    fwrite(&bg_color,sizeof(color),1,options_file);  
    fwrite(&point_color,sizeof(color),1,options_file); 
    fwrite(&punkt_color,sizeof(color),1,options_file);  
    fwrite(&word_color,sizeof(color),1,options_file);  
    fwrite(&negative_color,sizeof(color),1,options_file);
    fwrite(&options,sizeof(options),1,options_file);  
    fclose(options_file);
    printf(" завершено\n");  
    return;                             
}
