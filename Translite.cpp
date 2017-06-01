
#include <stdio.h>
#include <locale>
#include <conio.h>
#include "string.h"
#include <iostream>
 
int TransliteEN (char* str, char *newStr){
	setlocale(LC_ALL, "rus");
	FILE *fp1, *fp2;
	char ch = 'q';
	fp1=fopen("input1.txt", "r");
	fp2=fopen("output1.txt", "w");
    while (!feof(fp1)){
    	ch = getc(fp1);                      
    	switch (ch){
            case 'а': ch = 'f'; break;
            case '1': ch = ' '; break;
		}
	putc(ch,fp2);                    
    }
    fclose (fp1);
    fclose (fp2);
}


int main (){
	setlocale(LC_ALL,"Russian");
    char*str ; char*newStr;  
    char c;
    printf ("Чтобы зашифровать текст введите a, расшифровать b: ");
    scanf ("%c", &c);
    if (c == 'a') TransliteEN (str, newStr) ;
    if (c == 'b') TransliteDEC (str, newStr) ;
    printf ("Проверяйте фаил ");
	return 0;
}

