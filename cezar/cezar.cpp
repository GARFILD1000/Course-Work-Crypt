#include <stdio.h>
#include <locale>
 
#define ENG 26
#define RUS 32

void encrypt (int n)  //������� ��������
{
	setlocale(LC_ALL, "rus");
    FILE *fp1, *fp2;
//    ifstream fin(&fp1, "input.txt");
  //  ifstream fin(&fp2, "output.txt");
  fp1=fopen("input.txt", "r");
  fp2=fopen("output.txt", "w");

    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1))
    {
        flag = 0; 
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            fprintf (fp2, "c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c + (n % RUS);
            if (c > '�') c = '�' + (c - '�') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c>='�' && c<='�')
        {
            c = c + (n % RUS);
            if (c > '�') c = '�' + (c - '�') - 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf (fp2, "%c", c);
        c = getc(fp1);
    }
    fclose (fp1);
    fclose (fp2);
}


void decipher (int n)
{
    FILE *fp1, *fp2;
   fp1=fopen("input.txt", "r");
   fp2=fopen("output.txt", "w");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c - (n % ENG);
            if (c < 'A') c = 'Z' - ('A' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c - (n % ENG);
            if (c < 'a') c = 'z' - ('a' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % RUS);
            if (c < '�') c = '�' - ('�' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % RUS);
            if (c < '�') c = '�' - ('�' - c) + 1;
            fprintf (fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf (fp2, "%c", c);
        c = getc(fp1);
    }
    fclose (fp1);
    fclose (fp2);
}

int main ()
{
    setlocale(LC_ALL,"Russian");
    int n;
    printf ("������� ����������� n: ");
    scanf ("%d", &n);
    getchar (); //����� ��� ����, ����� ������� ������ ������� ENTER, ������� ��� ����� ����� n
    if (n < 1) return 0;
    printf ("����� ����������� ����� ������� a, ������������ b: ");
    char c;
    scanf ("%c", &c, 1);
    if (c == 'a') encrypt (n);
    if (c == 'b') decipher (n);
    return 0;
}
