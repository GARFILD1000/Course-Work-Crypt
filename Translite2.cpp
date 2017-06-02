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
            case '�': ch = 'f'; break;
        	case '�': ch = ','; break;
        	case '�': ch = 'd'; break;
            case '�': ch = 'u'; break;
            case '�': ch = 'l'; break;
            case '�': ch = 't'; break;
            case '�': ch = '`'; break;
            case '�': ch = ';'; break;
            case '�': ch = 'p'; break;
            case '�': ch = 'b'; break;
            case '�': ch = 'q'; break;
            case '�': ch = 'r'; break;
            case '�': ch = 'k'; break;
            case '�': ch = 'v'; break;
            case '�': ch = 'y'; break;
        	case '�': ch = 'j'; break;
            case '�': ch = 'g'; break;
            case '�': ch = 'h'; break;
            case '�': ch = 'c'; break;
            case '�': ch = 'n'; break;
            case '�': ch = 'e'; break;
            case '�': ch = 'a'; break;
            case '�': ch = '['; break;
            case '�': ch = 'w'; break;
            case '�': ch = 'x'; break;
            case '�': ch = 'i'; break;
            case '�': ch = 'o'; break;
            case '�': ch = ']'; break;
            case '�': ch = 's'; break;
            case '�': ch = 'm'; break;
            case '�': ch = '/'; break;
            case '�': ch = '.'; break;
            case '�': ch = 'z'; break;
            case '�': ch = 'F'; break;
            case '�': ch = '<'; break;
            case '�': ch = 'D'; break;
            case '�': ch = 'U'; break;
            case '�': ch = 'L'; break;
            case '�': ch = 'T'; break;
            case '�': ch = '~'; break;
            case '�': ch = ':'; break;
            case '�': ch = 'P'; break;
            case '�': ch = 'B'; break;
            case '�': ch = 'Q'; break;
            case '�': ch = 'R'; break;
            case '�': ch = 'K'; break;
            case '�': ch = 'V'; break;
            case '�': ch = 'Y'; break;
            case '�': ch = 'J'; break;
            case '�': ch = 'G'; break;
            case '�': ch = 'H'; break;
            case '�': ch = 'C'; break;
            case '�': ch = 'N'; break;
            case '�': ch = 'E'; break;
            case '�': ch = 'A'; break;
            case '�': ch = '{'; break;
            case '�': ch = 'W'; break;
            case '�': ch = 'X'; break;
            case '�': ch = 'I'; break;
            case '�': ch = 'O'; break;
            case '�': ch = '}'; break;
            case '�': ch = 'S'; break;
            case '�': ch = 'M'; break;
            case '�': ch = '3'; break;
            case '�': ch = '>'; break;
            case '�': ch = 'Z'; break;
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
            case 'f': ch = '�'; break;
        	case ',': ch = '�'; break;
        	case 'd': ch = '�'; break;
            case 'u': ch = '�'; break;
            case 'l': ch = '�'; break;
            case 't': ch = '�'; break;
            case '`': ch = '�'; break;
            case ';': ch = '�'; break;
            case 'p': ch = '�'; break;
            case 'b': ch = '�'; break;
            case 'q': ch = '�'; break;
            case 'r': ch = '�'; break;
            case 'k': ch = '�'; break;
            case 'v': ch = '�'; break;
            case 'y': ch = '�'; break;
        	case 'j': ch = '�'; break;
            case 'g': ch = '�'; break;
            case 'h': ch = '�'; break;
            case '�': ch = '�'; break;
            case 'n': ch = '�'; break;
            case 'e': ch = '�'; break;
            case 'a': ch = '�'; break;
            case '[': ch = '�'; break;
            case 'w': ch = '�'; break;
            case 'x': ch = '�'; break;
            case 'i': ch = '�'; break;
            case 'o': ch = '�'; break;
            case ']': ch = '�'; break;
            case 's': ch = '�'; break;
            case 'm': ch = '�'; break;
            case '/': ch = '�'; break;
            case '.': ch = '�'; break;
            case 'z': ch = '�'; break;
            case 'F': ch = '�'; break;
            case '<': ch = '�'; break;
            case 'D': ch = '�'; break;
            case 'U': ch = '�'; break;
            case 'L': ch = '�'; break;
            case 'T': ch = '�'; break;
            case '~': ch = '�'; break;
            case ':': ch = '�'; break;
            case 'P': ch = '�'; break;
            case 'B': ch = '�'; break;
            case 'Q': ch = '�'; break;
            case 'R': ch = '�'; break;
            case 'K': ch = '�'; break;
            case 'V': ch = '�'; break;
            case 'Y': ch = '�'; break;
            case 'J': ch = '�'; break;
            case 'G': ch = '�'; break;
            case 'H': ch = '�'; break;
            case 'C': ch = '�'; break;
            case 'N': ch = '�'; break;
            case 'E': ch = '�'; break;
            case 'A': ch = '�'; break;
            case '{': ch = '�'; break;
            case 'W': ch = '�'; break;
            case 'X': ch = '�'; break;
            case 'I': ch = '�'; break;
            case 'O': ch = '�'; break;
            case '}': ch = '�'; break;
            case 'S': ch = '�'; break;
            case 'M': ch = '�'; break;
            case '3': ch = '�'; break;
            case '>': ch = '�'; break;
            case 'Z': ch = '�'; break;
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
    printf ("����� ����������� ����� ������� a, ������������ b: ");
    scanf ("%c", &c);
    if (c == 'a') TransliteEN (str, newStr) ;
    if (c == 'b') TransliteDEC (str, newStr) ;
    printf ("���������� ���� ");
	return 0;
}
