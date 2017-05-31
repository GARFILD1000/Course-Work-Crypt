#include <stdio.h>
#include <locale>
#include <conio.h>
#include "string.h"
 
int Transliterate (char* с)
{
setlocale(LC_ALL, "rus");
FILE *fp1, *fp2;
  fp1=fopen("input.txt", "r");
  fp2=fopen("output.txt", "w");

        for (; *str != 0; str++)
        {
                switch (str[0])
                {
                case 'а': strcat(&newStr[0], "f"); break;
                case 'б': strcat(&newStr[0], ","); break;
                case 'в': strcat(&newStr[0], "d"); break;
                case 'г': strcat(&newStr[0], "u"); break;
                case 'д': strcat(&newStr[0], "l"); break;
                case 'е': strcat(&newStr[0], "t"); break;
                case 'ё': strcat(&newStr[0], "`"); break;
                case 'ж': strcat(&newStr[0], ";"); break;
                case 'з': strcat(&newStr[0], "p"); break;
                case 'и': strcat(&newStr[0], "b"); break;
                case 'й': strcat(&newStr[0], "q"); break;
                case 'к': strcat(&newStr[0], "r"); break;
                case 'л': strcat(&newStr[0], "k"); break;
                case 'м': strcat(&newStr[0], "v"); break;
                case 'н': strcat(&newStr[0], "y"); break;
                case 'о': strcat(&newStr[0], "j"); break;
                case 'п': strcat(&newStr[0], "g"); break;
                case 'р': strcat(&newStr[0], "h"); break;
                case 'с': strcat(&newStr[0], "c"); break;
                case 'т': strcat(&newStr[0], "n"); break;
                case 'у': strcat(&newStr[0], "e"); break;
                case 'ф': strcat(&newStr[0], "a"); break;
                case 'х': strcat(&newStr[0], "["); break;
                case 'ц': strcat(&newStr[0], "w"); break;
                case 'ч': strcat(&newStr[0], "x"); break;
                case 'ш': strcat(&newStr[0], "i"); break;
                case 'щ': strcat(&newStr[0], "o"); break;
                case 'ъ': strcat(&newStr[0], "]"); break;
                case 'ы': strcat(&newStr[0], "s"); break;
                case 'ь': strcat(&newStr[0], "m"); break;
                case 'э': strcat(&newStr[0], "'"); break;
                case 'ю': strcat(&newStr[0], "."); break;
                case 'я': strcat(&newStr[0], "z"); break;
                case 'А': strcat(&newStr[0], "F"); break;
                case 'Б': strcat(&newStr[0], "<"); break;
                case 'В': strcat(&newStr[0], "D"); break;
                case 'Г': strcat(&newStr[0], "U"); break;
                case 'Д': strcat(&newStr[0], "L"); break;
                case 'Е': strcat(&newStr[0], "T"); break;
                case 'Ё': strcat(&newStr[0], "~"); break;
                case 'Ж': strcat(&newStr[0], ":"); break;
                case 'З': strcat(&newStr[0], "P"); break;
                case 'И': strcat(&newStr[0], "B"); break;
                case 'Й': strcat(&newStr[0], "Q"); break;
                case 'К': strcat(&newStr[0], "R"); break;
                case 'Л': strcat(&newStr[0], "K"); break;
                case 'М': strcat(&newStr[0], "V"); break;
                case 'Н': strcat(&newStr[0], "Y"); break;
                case 'О': strcat(&newStr[0], "J"); break;
                case 'П': strcat(&newStr[0], "G"); break;
                case 'Р': strcat(&newStr[0], "H"); break;
                case 'С': strcat(&newStr[0], "C"); break;
                case 'Т': strcat(&newStr[0], "N"); break;
                case 'У': strcat(&newStr[0], "E"); break;
                case 'Ф': strcat(&newStr[0], "A"); break;
                case 'Х': strcat(&newStr[0], "{"); break;
                case 'Ц': strcat(&newStr[0], "W"); break;
                case 'Ч': strcat(&newStr[0], "X"); break;
                case 'Ш': strcat(&newStr[0], "I"); break;
                case 'Щ': strcat(&newStr[0], "O"); break;
                case 'Ъ': strcat(&newStr[0], "}'"); break;
                case 'Ы': strcat(&newStr[0], "S"); break;
                case 'Ь': strcat(&newStr[0], "M"); break;
                case 'Э': strcat(&newStr[0], " 3"); break;
                case 'Ю': strcat(&newStr[0], ">"); break;
                case 'Я': strcat(&newStr[0], "Z"); break;
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
    printf ("Чтобы зашифровать текст введите a, расшифровать b: ");
 
    scanf ("%c", &c);
    if (c == 'a') Transliterate (с) ;
	return 0;
}
