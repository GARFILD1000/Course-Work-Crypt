#include <stdio.h>
#include <locale>
#include <conio.h>
#include "string.h"
 
int Transliterate (char* �)
{
setlocale(LC_ALL, "rus");
FILE *fp1, *fp2;
  fp1=fopen("input.txt", "r");
  fp2=fopen("output.txt", "w");

        for (; *str != 0; str++)
        {
                switch (str[0])
                {
                case '�': strcat(&newStr[0], "f"); break;
                case '�': strcat(&newStr[0], ","); break;
                case '�': strcat(&newStr[0], "d"); break;
                case '�': strcat(&newStr[0], "u"); break;
                case '�': strcat(&newStr[0], "l"); break;
                case '�': strcat(&newStr[0], "t"); break;
                case '�': strcat(&newStr[0], "`"); break;
                case '�': strcat(&newStr[0], ";"); break;
                case '�': strcat(&newStr[0], "p"); break;
                case '�': strcat(&newStr[0], "b"); break;
                case '�': strcat(&newStr[0], "q"); break;
                case '�': strcat(&newStr[0], "r"); break;
                case '�': strcat(&newStr[0], "k"); break;
                case '�': strcat(&newStr[0], "v"); break;
                case '�': strcat(&newStr[0], "y"); break;
                case '�': strcat(&newStr[0], "j"); break;
                case '�': strcat(&newStr[0], "g"); break;
                case '�': strcat(&newStr[0], "h"); break;
                case '�': strcat(&newStr[0], "c"); break;
                case '�': strcat(&newStr[0], "n"); break;
                case '�': strcat(&newStr[0], "e"); break;
                case '�': strcat(&newStr[0], "a"); break;
                case '�': strcat(&newStr[0], "["); break;
                case '�': strcat(&newStr[0], "w"); break;
                case '�': strcat(&newStr[0], "x"); break;
                case '�': strcat(&newStr[0], "i"); break;
                case '�': strcat(&newStr[0], "o"); break;
                case '�': strcat(&newStr[0], "]"); break;
                case '�': strcat(&newStr[0], "s"); break;
                case '�': strcat(&newStr[0], "m"); break;
                case '�': strcat(&newStr[0], "'"); break;
                case '�': strcat(&newStr[0], "."); break;
                case '�': strcat(&newStr[0], "z"); break;
                case '�': strcat(&newStr[0], "F"); break;
                case '�': strcat(&newStr[0], "<"); break;
                case '�': strcat(&newStr[0], "D"); break;
                case '�': strcat(&newStr[0], "U"); break;
                case '�': strcat(&newStr[0], "L"); break;
                case '�': strcat(&newStr[0], "T"); break;
                case '�': strcat(&newStr[0], "~"); break;
                case '�': strcat(&newStr[0], ":"); break;
                case '�': strcat(&newStr[0], "P"); break;
                case '�': strcat(&newStr[0], "B"); break;
                case '�': strcat(&newStr[0], "Q"); break;
                case '�': strcat(&newStr[0], "R"); break;
                case '�': strcat(&newStr[0], "K"); break;
                case '�': strcat(&newStr[0], "V"); break;
                case '�': strcat(&newStr[0], "Y"); break;
                case '�': strcat(&newStr[0], "J"); break;
                case '�': strcat(&newStr[0], "G"); break;
                case '�': strcat(&newStr[0], "H"); break;
                case '�': strcat(&newStr[0], "C"); break;
                case '�': strcat(&newStr[0], "N"); break;
                case '�': strcat(&newStr[0], "E"); break;
                case '�': strcat(&newStr[0], "A"); break;
                case '�': strcat(&newStr[0], "{"); break;
                case '�': strcat(&newStr[0], "W"); break;
                case '�': strcat(&newStr[0], "X"); break;
                case '�': strcat(&newStr[0], "I"); break;
                case '�': strcat(&newStr[0], "O"); break;
                case '�': strcat(&newStr[0], "}'"); break;
                case '�': strcat(&newStr[0], "S"); break;
                case '�': strcat(&newStr[0], "M"); break;
                case '�': strcat(&newStr[0], " 3"); break;
                case '�': strcat(&newStr[0], ">"); break;
                case '�': strcat(&newStr[0], "Z"); break;
                fprintf (fp2, "%c");

			   }
	fclose (fp1);
    fclose (fp2);
       }
}


int main ()
{
    setlocale(LC_ALL,"Russian");
    char c;
    printf ("����� ����������� ����� ������� a, ������������ b: ");
 
    scanf ("%c", &c);
    if (c == 'a') Transliterate (�) ;
	return 0;
}
