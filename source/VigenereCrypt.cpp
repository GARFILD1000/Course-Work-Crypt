int WordToKey(int key[], char word[]);
int InputBox(int x1, int y1, short active, char word[]);
int CheckSymbolLang(int symbol);
int VigenereProcessingSymbol(int symbol, int key_symbol);
void StackFilesPath(char filename[],int InOrOut);
int VigenereCrypt(char word[]);
void VigenereWindow();

int InputBox(int x1, int y1, short active, char word[]){
    setlinestyle(0,0,2);
    settextstyle(3,0,2);
    settextjustify(0,0);
    setfillstyle(0,RGB(bg_color.red,bg_color.green,bg_color.blue));
    bar(x1,y1,x1+400,y1+40);
    
    int x=x1+5, y=y1+30, point, i; 
    if (active){
        
        char button;
        for (i=0; word[i]!=0; i++){
            if (word[i]==13){
                word[i]==0;
                break;
            };
        };
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        bar(x1,y1,x1+400,y1+40);
        rectangle(x1,y1,x1+400,y1+40);
        do{ 
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
            bar(x1,y1,x1+400,y1+40);
            rectangle(x1,y1,x1+400,y1+40);
            setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
            outtextxy(x,y,word); 
            printf("���� ������� %� ",button);
            printf("(%�)\n",word[i-1]);
            button=getch();
            
            if ((i<26)&&((button>=32)||(button<0)||(button==13))){
                word[i]=button;
                i++;
                word[i]=0;    
            };
            
            switch(button){
            case 8: 
                if (i>=0){
                    word[i]=0; 
                    if (i>0){
                        i--;
                        word[i]=0;
                    }; 
                }; 
            break; 
            case 75: break;
            case 77: break;
            case 72: break;
            case 80: break;
            case 13: word[i]=0; return 1;  break;
            case 27: return 0; break;
            };
        }while(1);
    }
    else{
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        rectangle(x1,y1,x1+400,y1+40);
        outtextxy(x,y,word);
        return 0;
    };
}

int CheckSymbolLang(int symbol){
    if ((symbol>191)&&(symbol<256)||(symbol==168)||(symbol==184)){
        return 1;
    }
    else if (((symbol>96)&&(symbol<123))||((symbol>54)&&(symbol<91))){
        return 2;
    }
    else return 0;
}

int VigenereProcessingSymbol(int symbol, int key_symbol){
    int lang;
    lang = CheckSymbolLang(symbol);
    
    switch(lang){
    case 0: return symbol;
    case 1: 
         
        if (symbol==168) symbol=197;              //������ � ���������� �� �
        if (symbol==184) symbol=229;             //������ � ���������� �� �  
        if ((symbol>191)&&(symbol<224)){
            symbol+=key_symbol;
            if (symbol>223) symbol=symbol-32;
        }
        if ((symbol>223)&&(symbol<256)){
            symbol+=key_symbol;
            if (symbol>255) symbol=symbol-32;
            
        }
        return symbol;
    case 2: 
        if ((symbol>64)&&(symbol<91)){
            symbol+=key_symbol;
            if (symbol>90) symbol=symbol-26;
        }
        if ((symbol>96)&&(symbol<123)){
            symbol+=key_symbol;
            if (symbol>122) symbol=symbol-26;
            
        }
    
        return symbol;
    };
};

//�������, ������������� ����� (���� �����) � �������� �������� ������� �������� �� ��������
int WordToKey(int key[], char word[]){
    int i=0, j=0;
    while(word[i]!=0){
    if (word[i]==-88) word[i]=-59;
    if (word[i]==-72) word[i]=-27;
    if ((word[i]<0)&&(word[i]>-33)) {key[j]=word[i]+32; j++;}
    else if ((word[i]<-32)&&(word[i]>-65)) {key[j]=word[i]+64; j++;}
    else if ((word[i]>64)&&(word[i]<91)) {key[j]=word[i]-65; j++;}
    else if ((word[i]>96)&&(word[i]<123)) {key[j]=word[i]-97; j++;}
    i++;
    };
    key[j]=-1;
    //int k=0;
    //while(k<=j){printf("%d ",key[k]); k++;};
}

//������� ���������� ������ ���� � �����, ��������� ������������ ������� � ��� � �������� ������ �����
//���� InOrOut ����� ����, �� ������ �������� �������� �����, ����� - ���������
void StackFilesPath(char filename[],int InOrOut){
    int k=0, j=0;
    while((options.file_directory[k]>31)||(options.file_directory[k]<0)){
        filename[k]=options.file_directory[k];
        k++;
        
    };
    if (!InOrOut){
        while((options.input_file_name[j]>31)||(options.input_file_name[j]<0)){
            filename[k]=options.input_file_name[j];
            k++;
            j++;
        };
    }
    else {
        while((options.output_file_name[j]>31)||(options.output_file_name[j]<0)){
            filename[k]=options.output_file_name[j];
            k++;
            j++;
        };
    };
    filename[k]=0;
    
};

//������� �������� ������� ��������, �������� �� ���� ����� - ���� �����
int VigenereCrypt(char word[]){
    FILE *input_file;
    FILE *output_file;
    int *key, symbol, word_length=0 ,key_length=0, i=0;
    char *output_filename, *input_filename;
    while (word[word_length]!=0){
        word_length++;
    }; 
    printf("����� ����������� �����: %d \n���� �����: %s\n",word_length-1, word);
    key = new int[word_length];
    WordToKey(key,word);
    
    while (key[key_length]!=-1){ 
        key_length++;
    };
    
    printf("\n����� ����� %d \n���������� ���� �����: \n",key_length);
    for(int j=0; j < key_length; j++){ 
        printf("%d ",key[j]);
    };
    printf("\n");
    if (key[0] == -1) return 3;
    
    input_filename=new char[100];
    output_filename=new char[100];
    StackFilesPath(input_filename, 0);
    StackFilesPath(output_filename, 1);
    printf("������� ���� %s\n",input_filename);
    printf("�������� ���� %s\n",output_filename);
        
    printf("�������� �������� ����� ");
    if ((input_file=fopen(input_filename,"r")) == NULL){
    printf("�� ������!");
    return 1;
    };
    printf("���������\n");
    printf("�������� ��������� ����� ");
    if ((output_file=fopen(output_filename,"w")) == NULL){
    printf("�� ������!");
    return 2;
    };
    printf("���������\n");

    printf("�������� ��������...\n");
    while((symbol=fgetc(input_file))!=EOF){
        //printf(" (%c %d) ",symbol, symbol);
        symbol=VigenereProcessingSymbol(symbol,key[i]); 
        //printf("=> (%c %d) \n",symbol, symbol);
        fputc(symbol,output_file);
        if (CheckSymbolLang(symbol)!=0){
            if (i!=key_length-1) i++;
            else i=0;
        };
    };
    printf("�����������!\n");
    fclose(input_file);
    fclose(output_file);
    return 0;
};

//������� ��������� �� ����� � ����������� �� ���������� ������ ������� VisenereCrypt
void VisenereShowMessage(int result){
    settextjustify(1,1);
    settextstyle(1,0,3);
    bar(100,100,500,300);
    if (!result) setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
    else setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
    rectangle(100,100,500,300);
    switch(result){
    case 0: 
        outtextxy(300,200,"�����������!"); 
    break;
    case 1: 
        outtextxy(300,180,"������� ������"); 
        outtextxy(300,220,"���� ��� ����������!"); 
    break;
    case 2: 
        outtextxy(300,180,"������� ������"); 
        outtextxy(300,220,"���� � �����������!"); 
    break;
    case 3: 
        outtextxy(300,180,"�������");
        outtextxy(300,220,"���������� ����!"); 
    break;
    };
    getch();
}

void VigenereWindow(){             //������� ����������
    char *input_filename, *output_filename, *word, *temp_word; 
    int k=0; 
    input_filename=new char[50];
    output_filename=new char[50];
    word=new char[50];
    temp_word=new char[50];
    word[0]=0;      
    temp_word[0]=0;
    do{
        input_filename[k]=options.input_file_name[k];
        k++;
    }while (options.input_file_name[k-1] != 0);
    k=0;
    do{
        output_filename[k]=options.output_file_name[k];
        k++;
    }while (options.output_file_name[k-1] != 0);
    k=0;         
    
    int button, point=1;
    do{
        cleardevice();
        settextjustify(1,1);
        settextstyle(1,0,5);
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,50,"���� ��������"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextstyle(1,0,3); 
        if (point == 1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,100,"�������� �������� ����");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,180,"�������� ������������� ����");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,260,"������� ���� �����");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 4) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,340,"�����������!");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 5) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,370,"�����");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        InputBox(100,110,0,options.input_file_name);
        InputBox(100,190,0,options.output_file_name);
        InputBox(100,270,0,word);
        button=getch();
        switch(button){
        case 72: if (point > 1) point--; break;
        case 80: if (point < 5) point++; break;
        case 13: 
            switch(point){
            case 1: 
                if (InputBox(100,110,1,input_filename)) options.input_file_name=input_filename; 
                printf("\n Return: "); 
                printf("%s ", input_filename); 
            break;
            case 2: 
                if (InputBox(100,190,1,output_filename)) options.output_file_name=output_filename; 
                printf("\n Return: "); 
                printf("%s ", output_filename); 
            break;
            case 3: 
                if (InputBox(100,270,1,temp_word)) word=temp_word; 
                printf("\n Return: "); 
                printf("%s ", word); 
            break;
            case 4: 
                int result;
                result = VigenereCrypt(word);
                VisenereShowMessage(result);
            break;
            case 5: return; 
            };      
        break; 
        case 27: return;
        };
    }while (1);        
}    
