int InputBox(int x1, int y1, short active, char word[]){
    int previous_textstyle, previous_linestyle, previous_textjustify;
    setlinestyle(0,0,2);
    settextstyle(4,0,2);
    settextjustify(0,0);
    setfillstyle(0,RGB(bg_color.red,bg_color.green,bg_color.blue));
    bar(x1,y1,x1+400,y1+40);
    
    int  symbol, x=102, y=y1+30, point, i; 
    if (active){
        //for (int k=0; k<50; k++) word[k]=0;
        char button;
        char *symbol_out=new char[2];
        setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        rectangle(x1,y1,x1+400,y1+40);
        i=0;
        do{ 
            button=symbol=getch();
            if ((i<26)&&(button!=224)&&((button<0)||(button>=33)&&(button<=126))){
                word[i]=symbol;
                i++;
                
                symbol_out[0]=button;
                setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
                outtextxy(x,y,symbol_out); printf("Ввод символа %d",symbol);
                printf("(%d)",word[i-1]);
                x+=15;
            };
            switch(button){
            case 8: if (i>=0){word[i]=0; if (i>0){i--;  x-=15;}; bar(x,y,x+15,y-20); }; break; 
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
         
        if (symbol==168) symbol=197;              //символ Ё заменяется на Е
        if (symbol==184) symbol=229;             //символ ё заменяется на е  
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

int VigenereCrypt(int key[]){
    FILE *input_file, *output_file;
    int k, symbol;
    int key_length=0, i=0;printf("Открытие входного файла\n");
    printf("Входной%s",options.input_file_name);
    printf("\nВыходной %s\n",options.output_file_name);
    while(key[k]!=-1){printf("%d ",key[k]); k++;};
    //if (( == NULL){ 
     //   return 0;
    //};
    
    printf("Создание выходного файла\n");
    output_file=fopen(options.output_file_name,"w");
    
    input_file=fopen(options.input_file_name,"r");
    printf("Ключ шифра: ");
    while(key[key_length]!=-1){printf("%d ",key[key_length]); key_length++;};
    printf("\nЗадаётся в функции MenuCategory в массиве key \n");
    
    while((symbol=fgetc(input_file))!=EOF){
        //printf(" (%c %d) ",symbol, symbol);
        symbol=VigenereProcessingSymbol(symbol,key[i]); 
        //printf("=> (%c %d) \n",symbol, symbol);
        fputc(symbol,output_file);
        
        if ((CheckSymbolLang(symbol)!=0)&&(i!=key_length-1)){
            i++;
        }
        else {
            i=0;
        };   
    };
    fclose(output_file);
    fclose(input_file);
    return 1;
};

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
    int k=0;
    while(k<=j){printf("%d ",key[k]); k++;};
}

int VigenereWindow(){             //подменю зашифровки
    char *input_filename, *output_filename, *word, key_length=0;  
    input_filename=new char[50];
    output_filename=new char[50];
    word=new char[50];      
    word[0]=0; 
              
    int *key;       //массив ключей, -1 даёт знать, что это конец массива
    int button, point=1;
    do{
        cleardevice();
        settextjustify(1,1);
        settextstyle(1,0,5);
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,50,"Шифр Виженера"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextstyle(1,0,3); 
        if (point==1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,100,"Назовите исходный файл");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,180,"Назовите зашифрованный файл");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,260,"Введите ключ шифра");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==4) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,340,"Зашифровать!");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point==5) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,370,"Назад");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        
        InputBox(100,110,0,options.input_file_name);
        InputBox(100,190,0,options.output_file_name);
        InputBox(100,270,0,word);
        int k=0;
        button=getch();
        switch(button){
        case 72: if (point>1) point--; break;
        case 80: if (point<5) point++; break;
        case 13: 
                switch(point){
                case 1: InputBox(100,110,1,input_filename); options.input_file_name=input_filename; printf("\nReturn: "); printf("%s ", input_filename); break;
                case 2: InputBox(100,190,1,output_filename); options.output_file_name=output_filename; printf("\nReturn: "); printf("%s ", output_filename); break;
                case 3: InputBox(100,270,1,word);  printf("\nReturn: "); printf("%s ", word); break;
                case 4: 
                    while (word[key_length]!=0) key_length++; 
                    key = new int[key_length];
                    //key[key_length]=-1;
                    printf("Преобразование слова в ключ");
                    WordToKey(key, word); 
                    printf(" завершено\n");
                    VigenereCrypt(key);
                     
                    break;
                case 5: cleardevice(); return 0; break;
                };      
        break; 
        case 27: cleardevice(); return 0;
        };
    } while(1);        
}    
