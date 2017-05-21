int WordToKey(int key[], char word[]);
int InputBox(int x1, int y1, short active, char word[]);
int CheckSymbolLang(int symbol);
int VigenereProcessingSymbol(int symbol, int key_symbol);
void StackFilesPath(char filename[],int InOrOut);
int VigenereCrypt(char word[]);
void VigenereWindow();
int CutWord(char word[], char cut_word[], int first, int last);
int DeleteSymbol(char word[], int num);
int AddSymbol(char word[], char symbol, int num);


int WordToCache(char word[]){
    FILE *cache_file; 
    FILE *temp_file;
    char symbol;
    int num=1, i=0;
    if ((cache_file=fopen("..\\saves\\cache.txt","r+"))==NULL){
        printf("Файл с кэшем не открылся ");
        fclose(cache_file);
        cache_file=fopen("..\\saves\\cache.txt","w+");
        printf("создался новый\n");
    };
    if ((word[0] == 13)||(word[0] == 0)){
        fclose(cache_file);
        return 0;
    };
    temp_file=fopen("..\\saves\\temp_cache.txt","w+");
    while(word[i] != 0){
        fputc(word[i],temp_file);
        i++;
    };
    fputc(10,temp_file);
    while((symbol=fgetc(cache_file)) != EOF){
        fputc(symbol,temp_file);
    };
    fclose(cache_file);
    fclose(temp_file);
    if (remove("..\\saves\\cache.txt")){
        printf("Ошибка удаления\n"); 
        perror("Проблема в ");
    };
    if (rename("..\\saves\\temp_cache.txt","..\\saves\\cache.txt")) printf("Oшибка переименования\n");
    return 1;    
}

int WordFromCache(char word[], int num_of_word){
    FILE *cache_file;
    char symbol;
    int num=1, i=0;
    if (num_of_word <= 0) return 0;
    if ((cache_file=fopen("..\\saves\\cache.txt","r"))==NULL){
        printf("Файла с кэшем нет,создаётся новый... ");
        fclose(cache_file);
        cache_file=fopen("..\\saves\\cache.txt","w");
        printf("создано!\n");
        fclose(cache_file);
        return 0;
    };
    if (num < num_of_word){
        while((symbol=fgetc(cache_file)) != EOF){
            if (symbol == 10){ 
                num++;
                if (num == num_of_word) break;
            };
        };
    };
    if (num < num_of_word){ 
        fclose(cache_file);
        return 0;
    };
    while((symbol=fgetc(cache_file)) != EOF){
        if (symbol == 10) break;
        word[i]=symbol;
        i++;
    };
    word[i-1]=0;
    fclose(cache_file);
    return 1;    
}

int CutWord(char word[], char cut_word[], int first, int last){
    if (first > last) return 0;
    int j=0;
    for (int i=first; i <= last; i++){ 
        cut_word[j]=word[i];    
        j++;
    };
    cut_word[j]=0;
    return 1;
}

//функция удаления символа с порядковым номером num 
//из строки word
//возвращает 1, если символ был удалён, иначе 0
int DeleteSymbol(char word[], int num){
    int i=0;
    while (word[i]!=0) i++;
    if (num >= i) return 0;
    for (int i=num; word[i]!=0; i++){
        word[i]=word[i+1];
    };
    return 1;
}

//функция добавляет символ symbol в строку word
//после символа с порядковым номером num
//возвращает 1, если символ добавлен, иначе 0
int AddSymbol(char word[], char symbol, int num){
    int i=0;
    char temp;
    temp=word[i];
    while (word[i]!=0) i++;
    if (num > i) return 0;
    while (i>=num){ 
        word[i+1]=word[i];
        i--;
    };
    word[num]=symbol;
    return 1;
}

//функция, изображающая поле ввода строки
//ввод активен, если параметр active ненулевой
//позволяет добавлять символы в строку, удалять их клавишей backspase 
//и перемещаться по вводимой строке клавишами со стрелками
int InputBox(int x1, int y1, short active, char word[]){
    setlinestyle(0,0,2);
    settextstyle(8,0,2);
    settextjustify(0,0);
    setfillstyle(0,RGB(bg_color.red,bg_color.green,bg_color.blue));
    bar(x1,y1,x1+400,y1+40);
    char *temp_word;
    char button;
    int x=x1+5, y=y1+30, word_size=0, left_barrier=0, box_size=32; 
    for (word_size=0; word[word_size]!=0; word_size++){
            if (word[word_size]==13){
                word[word_size]==0;
                break;
            };
    };
    temp_word=new char[box_size+1];
    CutWord(word, temp_word, left_barrier, left_barrier+box_size-1);
    
    if (active){
        int cursor, cursor_x, moving=0, num_of_word=0; 
        if (word_size > box_size) left_barrier=word_size-box_size;
            cursor=word_size-left_barrier;
        do{ 
            
            setcolor(RGB(point_color.red,point_color.green,point_color.blue));
            bar(x1,y1,x1+400,y1+40);
            rectangle(x1,y1,x1+400,y1+40);
            setcolor(RGB(word_color.red,word_color.green,word_color.blue));
            cursor_x=x+(cursor-left_barrier)*12;
            line(cursor_x+2,y+5,cursor_x+10,y+5);
            CutWord(word, temp_word, left_barrier, left_barrier+box_size-1);
            outtextxy(x,y,temp_word);  
            button=getch();
            if (moving == 0){
                if (button == 13) cursor=word_size;       
                if ((word_size < 49)&&((button>=32)||(button<0)||(button==13))){
                    AddSymbol(word, button, cursor);
                    word_size++; 
                    word[word_size]=0;
                    if (word_size>box_size) left_barrier++; 
                    cursor++;
                };
                switch(button){
                case 8: 
                    if ((word_size >= 0)&&(cursor !=0)){
                        DeleteSymbol(word, cursor-1);
                        if (word_size != 0){
                            if (word[0] != 0) word_size--; 
                            if (left_barrier > 0) left_barrier--;
                        };
                        if (cursor > 0) cursor--; 
                    }; 
                break;  
                case 13: 
                    word[word_size]=0; 
                    WordToCache(word); 
                    return 1;
                case 27: return 0;
                }
            }
            else{
                switch (button){
                case 75: 
                    if (cursor > left_barrier) cursor--; 
                    else if (left_barrier > 0){
                        cursor--; 
                        left_barrier--;
                    }; 
                break;
                case 77: 
                    if ((cursor < left_barrier+box_size) && (cursor < word_size)) cursor++; 
                    else if ((cursor < word_size) && ((left_barrier+box_size) < word_size)){
                        cursor++; 
                        left_barrier++;
                    };  
                break;
                case 46:
                    if (word_size >= 0){
                        DeleteSymbol(word, cursor);
                        if (word_size != 0){
                            if (word[0] != 0) word_size--; 
                            if (left_barrier > 0) left_barrier--;
                        };
                        //if (cursor > 0) cursor--; 
                    };  
                case 72: 
                    if (WordFromCache(word,num_of_word+1)) num_of_word++; 
                    for (word_size=0; word[word_size]!=0; word_size++);
                    cursor=box_size;
                    printf("Номер слова из кэша %d \n",num_of_word);  
                    if (word_size > box_size) left_barrier=word_size-box_size;
                    else left_barrier=0;
                    cursor=word_size;
                break;
                case 80: 
                    if (num_of_word > 0){ 
                        num_of_word--;
                        WordFromCache(word,num_of_word); 
                        if (num_of_word == 0) word[0]=0;
                        for (word_size=0; word[word_size]!=0; word_size++);
                        if (word_size > box_size) left_barrier=word_size-box_size;
                        else left_barrier=0;
                        cursor=word_size;
                        printf("Номер слова из кэша %d \n",num_of_word);
                    }; 
                break; 
                };
                moving = 0;
            };
            if (button == 0) moving=1;
            else moving=0; 
        }while(1);
    }
    else{
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        rectangle(x1,y1,x1+400,y1+40);
        outtextxy(x,y,temp_word);
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

//функция, сдвигающая символ symbol вправо по алфавиту на величину key_symbol
int VigenereCryptProcessing(int symbol, int key_symbol){
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

//функция, преобразующая слово (ключ шифра) в числовые значения сдвигов символов по алфавиту
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

//функция составляет полный путь к файлу, складывая расположение каталга с ним и название самого файла
//если InOrOut равен нулю, то берётся название входного файла, иначе - выходного
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


//функция шифровки методом Виженера, получает на вход слово - ключ шифра
int VigenereCrypt(char word[]){
    FILE *input_file;
    FILE *output_file;
    int *key, symbol, word_length=0 ,key_length=0, i=0;
    char *output_filename, *input_filename;
    while (word[word_length]!=0){
        word_length++;
    }; 
    printf("Длина полученного слова: %d \nСамо слово: %s\n",word_length-1, word);
    key = new int[word_length];
    WordToKey(key,word);
    
    while (key[key_length]!=-1){ 
        key_length++;
    };
    
    printf("\nДлина ключа %d \nПолученный ключ шифра: \n",key_length);
    for(int j=0; j < key_length; j++){ 
        printf("%d ",key[j]);
    };
    printf("\n");
    if (key[0] == -1) return 3;
    
    input_filename=new char[100];
    output_filename=new char[100];
    StackFilesPath(input_filename, 0);
    StackFilesPath(output_filename, 1);
    printf("Входной файл %s\n",input_filename);
    printf("Выходной файл %s\n",output_filename);
    if (strcmp(input_filename,output_filename)==0) return 4;
    printf("Открытие входного файла ");
    if ((input_file=fopen(input_filename,"r")) == NULL){
    printf("Не открыл!");
    return 1;
    };
    printf("Завершено\n");
    printf("Создание выходного файла ");
    if ((output_file=fopen(output_filename,"w")) == NULL){
    printf("Не создал!");
    return 2;
    };
    printf("Завершено\n");

    printf("Шифровка началась...\n");
    while((symbol=fgetc(input_file))!=EOF){
        //printf(" (%c %d) ",symbol, symbol);
        symbol=VigenereCryptProcessing(symbol,key[i]); 
        //printf("=> (%c %d) \n",symbol, symbol);
        fputc(symbol,output_file);
        if (CheckSymbolLang(symbol)!=0){
            if (i!=key_length-1) i++;
            else i=0;
        };
    };
    printf("Зашифровано!\n");
    fclose(input_file);
    fclose(output_file);
    return 0;
};

//выводит сообщение на экран в зависимости от результата работы функции VisenereCrypt
void ShowMessage(int result){
    settextjustify(1,1);
    settextstyle(1,0,3);
    bar(100,100,500,300);
    if (!result) setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
    else setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
    rectangle(100,100,500,300);
    switch(result){
    case 0: 
        outtextxy(300,200,"Зашифровано!"); 
    break;
    case 1: 
        outtextxy(300,180,"Неверно назван"); 
        outtextxy(300,220,"файл для зашифровки!"); 
    break;
    case 2: 
        outtextxy(300,180,"Неверно назван"); 
        outtextxy(300,220,"файл с результатом!"); 
    break;
    case 3: 
        outtextxy(300,180,"Введите");
        outtextxy(300,220,"правильный ключ!"); 
    break;
    case 4: 
        outtextxy(300,160,"Файлы не должны");
        outtextxy(300,200,"совпадать"); 
        outtextxy(300,240,"по названию!"); 
    break;
    case 5: 
        outtextxy(300,200,"Расшифровано!"); 
    break;
    };
    getch();
}

void VigenereCryptWindow(){             //меню зашифровки методом Виженера
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
    input_filename=options.input_file_name;
    output_filename=options.output_file_name;
    int button, point=1;
    do{ 
        cleardevice();
        settextjustify(1,1);
        settextstyle(1,0,5);
        setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,50,"Шифр Виженера"); 
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        settextstyle(1,0,3); 
        if (point == 1) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,100,"Назовите исходный файл");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 2) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,180,"Назовите зашифрованный файл");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 3) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,260,"Введите ключ шифра");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 4) setcolor(RGB(point_color.red,point_color.green,point_color.blue));
        outtextxy(300,340,"Зашифровать!");
        setcolor(RGB(punkt_color.red,punkt_color.green,punkt_color.blue));
        if (point == 5) setcolor(RGB(negative_color.red,negative_color.green,negative_color.blue));
        outtextxy(300,370,"Назад");
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
                printf("Открывается поле ввода\n");
                InputBox(100,110,1,options.input_file_name); 
                printf("\nВведено: "); 
                printf("%s ", input_filename); 
            break;
            case 2: 
                printf("Открывается поле ввода\n");
                InputBox(100,190,1,options.output_file_name);
                printf("\nВведено: ");
                printf("%s ", output_filename);
            break;
            case 3:
                printf("Открывается поле ввода\n"); 
                if (InputBox(100,270,1,temp_word)) word=temp_word;
                printf("\nВведено: "); 
                printf("%s ", word); 
                for (int i=0; ; i++) if (word[i]==0){word[i]=13; word[i+1]=0; break;}; 
            break;
            case 4: 
                int result;
                result = VigenereCrypt(word);
                ShowMessage(result);
            break;
            case 5: return; 
            };      
        break; 
        case 27: return;
        };
    }while (1);        
}    
