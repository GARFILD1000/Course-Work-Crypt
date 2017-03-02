#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int proverka(float srok,float sum){
    if ((sum < 10000) || (srok < 0 || srok > 365)) {
    return 1;
    }
    else return 0;
}

int main() {
float srok, sum;
int check;
    setlocale (LC_ALL, "rus");
    do {
        printf ("Введите cумму вклада ");
        scanf ("%f", &sum);
        printf ("Введите срок вклада ");
        scanf ("%f", &srok);
        check=proverka(srok,sum);
        if (check == 1) {
            printf ("Неверно введены данные, введите заново:\n");
        };
    } while (check);
    if (srok < 31) {
        sum-=sum/10;
    };
    if ((srok >= 31) && (srok < 121)) {
        sum+=sum/50;
    };
    if ((srok >= 121) && (srok < 241)) {
        sum+=(sum/100)*6;
    };
    if (srok >= 241) {
        sum+=(sum/100)*12;
    };
    printf("Сумма вклада на момент окончания срока: \n%.0f\n ", sum); 
}
