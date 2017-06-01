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
        	case 'б': ch = ','; break;
        	case 'в': ch = 'd'; break;
            case 'г': ch = 'u'; break;
            case 'д': ch = 'l'; break;
            case 'е': ch = 't'; break;
            case 'ё': ch = '`'; break;
            case 'ж': ch = ';'; break;
            case 'з': ch = 'p'; break;
            case 'и': ch = 'b'; break;
            case 'й': ch = 'q'; break;
            case 'к': ch = 'r'; break;
            case 'л': ch = 'k'; break;
            case 'м': ch = 'v'; break;
            case 'н': ch = 'y'; break;
        	case 'о': ch = 'j'; break;
            case 'п': ch = 'g'; break;
            case 'р': ch = 'h'; break;
            case 'с': ch = 'c'; break;
            case 'т': ch = 'n'; break;
            case 'у': ch = 'e'; break;
            case 'ф': ch = 'a'; break;
            case 'х': ch = '['; break;
            case 'ц': ch = 'w'; break;
            case 'ч': ch = 'x'; break;
            case 'ш': ch = 'i'; break;
            case 'щ': ch = 'o'; break;
            case 'ъ': ch = ']'; break;
            case 'ы': ch = 's'; break;
            case 'ь': ch = 'm'; break;
            case 'э': ch = '/'; break;
            case 'ю': ch = '.'; break;
            case 'я': ch = 'z'; break;
            case 'А': ch = 'F'; break;
            case 'Б': ch = '<'; break;
            case 'В': ch = 'D'; break;
            case 'Г': ch = 'U'; break;
            case 'Д': ch = 'L'; break;
            case 'Е': ch = 'T'; break;
            case 'Ё': ch = '~'; break;
            case 'Ж': ch = ':'; break;
            case 'З': ch = 'P'; break;
            case 'И': ch = 'B'; break;
            case 'Й': ch = 'Q'; break;
            case 'К': ch = 'R'; break;
            case 'Л': ch = 'K'; break;
            case 'М': ch = 'V'; break;
            case 'Н': ch = 'Y'; break;
            case 'О': ch = 'J'; break;
            case 'П': ch = 'G'; break;
            case 'Р': ch = 'H'; break;
            case 'С': ch = 'C'; break;
            case 'Т': ch = 'N'; break;
            case 'У': ch = 'E'; break;
            case 'Ф': ch = 'A'; break;
            case 'Х': ch = '{'; break;
            case 'Ц': ch = 'W'; break;
            case 'Ч': ch = 'X'; break;
            case 'Ш': ch = 'I'; break;
            case 'Щ': ch = 'O'; break;
            case 'Ъ': ch = '}'; break;
            case 'Ы': ch = 'S'; break;
            case 'Ь': ch = 'M'; break;
            case 'Э': ch = '3'; break;
            case 'Ю': ch = '>'; break;
            case 'Я': ch = 'Z'; break;
            case ' ': ch = '1'; break;
		}
	putc(ch,fp2);                    
    }
    fclose (fp1);
    fclose (fp2);
}


int TransliteDEC (char* str, char *newStr){
	setlocale(LC_ALL, "rus");
	FILE *fp1, *fp2;
	char ch = 'q';
	fp1=fopen("input2.txt", "r");
	fp2=fopen("output2.txt", "w");
    while (!feof(fp1)){
    	ch = getc(fp1);                      
    	switch (ch){
            case 'f': ch = 'а'; break;
        	case ',': ch = 'б'; break;
        	case 'd': ch = 'в'; break;
            case 'u': ch = 'г'; break;
            case 'l': ch = 'д'; break;
            case 't': ch = 'е'; break;
            case '`': ch = 'ё'; break;
            case ';': ch = 'ж'; break;
            case 'p': ch = 'з'; break;
            case 'b': ch = 'и'; break;
            case 'q': ch = 'й'; break;
            case 'r': ch = 'к'; break;
            case 'k': ch = 'л'; break;
            case 'v': ch = 'м'; break;
            case 'y': ch = 'н'; break;
        	case 'j': ch = 'о'; break;
            case 'g': ch = 'п'; break;
            case 'h': ch = 'р'; break;
            case 'с': ch = 'с'; break;
            case 'n': ch = 'т'; break;
            case 'e': ch = 'у'; break;
            case 'a': ch = 'ф'; break;
            case '[': ch = 'х'; break;
            case 'w': ch = 'ц'; break;
            case 'x': ch = 'ч'; break;
            case 'i': ch = 'ш'; break;
            case 'o': ch = 'щ'; break;
            case ']': ch = 'ъ'; break;
            case 's': ch = 'ы'; break;
            case 'm': ch = 'ь'; break;
            case '/': ch = 'э'; break;
            case '.': ch = 'ю'; break;
            case 'z': ch = 'я'; break;
            case 'F': ch = 'А'; break;
            case '<': ch = 'Б'; break;
            case 'D': ch = 'В'; break;
            case 'U': ch = 'Г'; break;
            case 'L': ch = 'Д'; break;
            case 'T': ch = 'Е'; break;
            case '~': ch = 'Ё'; break;
            case ':': ch = 'Ж'; break;
            case 'P': ch = 'З'; break;
            case 'B': ch = 'И'; break;
            case 'Q': ch = 'Й'; break;
            case 'R': ch = 'К'; break;
            case 'K': ch = 'Л'; break;
            case 'V': ch = 'М'; break;
            case 'Y': ch = 'Н'; break;
            case 'J': ch = 'О'; break;
            case 'G': ch = 'П'; break;
            case 'H': ch = 'Р'; break;
            case 'C': ch = 'С'; break;
            case 'N': ch = 'Т'; break;
            case 'E': ch = 'У'; break;
            case 'A': ch = 'Ф'; break;
            case '{': ch = 'Х'; break;
            case 'W': ch = 'Ц'; break;
            case 'X': ch = 'Ч'; break;
            case 'I': ch = 'Ш'; break;
            case 'O': ch = 'Щ'; break;
            case '}': ch = 'Ъ'; break;
            case 'S': ch = 'Ы'; break;
            case 'M': ch = 'Ь'; break;
            case '3': ch = 'Э'; break;
            case '>': ch = 'Ю'; break;
            case 'Z': ch = 'Я'; break;
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
