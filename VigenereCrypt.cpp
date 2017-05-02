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

int VigenereCrypt(int *key){
    FILE *input_file, *output_file;
    int symbol;
    int key_length, i=0;
    if ((input_file=fopen(options.input_file_name,"r")) == NULL){ 
        return 0;
    };
    output_file=fopen(options.output_file_name,"w");
    printf("Ключ шифра: ");
    while(key[i]!=-1){printf("%d ",key[i]); i++;};
    printf("\nЗадаётся в функции MenuCategory в массиве key \n");
    for(key_length=0; key[key_length]!=-1 ; key_length++);
    i=0;
    while((symbol=fgetc(input_file))!=EOF){
        printf(" (%c %d) ",symbol, symbol);
        symbol=VigenereProcessingSymbol(symbol,key[i]); 
        printf("=> (%c %d) \n",symbol, symbol);
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
