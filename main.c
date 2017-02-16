#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
float srok, sum;
    setlocale(LC_ALL,"rus");
    printf("Vvedyte srok vklada ");
    scanf("%f",&srok);
    printf("Vvedyte summu vklada ");
    scanf("%f",&sum);
    do{
        printf("Neverno vvedeny dannye, vvedyte zanovo \n");
        printf("Vvedyte srok vklada ");
        scanf("%f",&srok);
        printf("Vvedyte summu vklada ");
        scanf("%f",&sum);
    }while((sum < 10000)||(srok < 0 || srok > 365));
    if (srok < 31) {
        sum-=sum/10;
    };
    if ((srok >= 31)&&(srok<121)) {
        sum+=sum/50;
    };
    if ((srok >= 121)&&(srok<241)) {
        sum+=(sum/100)*6;
    };
    if (srok >= 241) {
        sum+=(sum/100)*12;
    };
    printf("Сумма вклада на момент окончания срока \n%.0f",sum); 
}

