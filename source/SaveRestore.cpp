void RestoreOptions();
void RestoreOptionsWindow();

//   ��������� ��������� ��������� � ���������� ������������ ����������
void RestoreOptions(){
    point_color.blue=200;
    point_color.green=50;
    point_color.red=50;
    
    punkt_color.blue=200;
    punkt_color.green=200;
    punkt_color.red=200;
    
    word_color.blue=200;
    word_color.green=200;
    word_color.red=200;
    
    negative_color.blue=20;
    negative_color.green=20;
    negative_color.red=250;
    
    bg_color.red=0;
    bg_color.blue=0;
    bg_color.green=0;
    
    options.input_file_name="InputFile.txt";
    options.output_file_name="OutputFile.txt";
    options.file_directory="..\\files\\";
}

void RestoreOptionsWindow(){
    int point=1, button; 
    do{ cleardevice();
        outtextxy(300,70,"��������");
        outtextxy(300,100,"���������?");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==1) {
            outtextxy(300,250,"��������� � ����������");
            setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
            outtextxy(300,280,"���������");
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        };
        outtextxy(300,160,"��");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) {
            
            outtextxy(300,250,"��������� � ����������");
            outtextxy(300,280,"�� ���������");
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        };
        outtextxy(300,190,"���");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        button = getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<2) point++; break;
        case 13: RestoreOptions(); return;
        };
    }while(1);                                           
}

//   ��������� ��������� ��������� � ���������� �� ����� options.dat � �������������� ���������
//   ���� ����� ����� ��� � ��������, ������ ��� � ��������� ������������ ����������
void LoadOptions(){
    FILE *options_file;
    if ((options_file=fopen("..//saves//options.dat","rb"))==NULL){
        options_file=fopen("..//saves//options.dat","wb");
        RestoreOptions();
    };
    fread(&options,sizeof(options),1,options_file);  
    fread(&bg_color,sizeof(color),1,options_file);  
    fread(&point_color,sizeof(color),1,options_file);
    fread(&punkt_color,sizeof(color),1,options_file);  
    fread(&word_color,sizeof(color),1,options_file);  
    fread(&negative_color,sizeof(color),1,options_file);
    fclose(options_file);
    return;
}

// ��������� ��������� ��������� � ���������� � ���� options.dat
void SaveOptions(){
    FILE *options_file;
    options_file=fopen("..//saves//options.dat","wb");
    fwrite(&options,sizeof(options),1,options_file);  
    fwrite(&bg_color,sizeof(color),1,options_file);  
    fwrite(&point_color,sizeof(color),1,options_file); 
    fwrite(&punkt_color,sizeof(color),1,options_file);  
    fwrite(&word_color,sizeof(color),1,options_file);  
    fwrite(&negative_color,sizeof(color),1,options_file);
    fclose(options_file);  
    return;                             
}
