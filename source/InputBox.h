#ifndef INPUTBOX_H
#define INPUTBOX_H
int CutWord(char word[], char cut_word[], int first, int last);
int DeleteSymbol(char word[], int num);
int AddSymbol(char word[], char symbol, int num);
int WordToCache(char word[]);
int WordFromCache(char word[], int num_of_word);
int InputBox(int x1, int y1, short active, char word[]);
#endif
