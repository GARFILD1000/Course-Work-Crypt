#ifndef VIGENERECRYPT_H
#define VIGENERECRYPT_H
int WordToKey(int key[], char word[]);
int CheckSymbolLang(int symbol);
int VigenereCryptProcessing(int symbol, int key_symbol);
int VigenereCrypt(char word[]);
void VigenereCryptWindow();
void ShowMessage(int result);
void StackString(char string1[], char string2[], char result[]);
int CopyString(char string[], char copy[]);
#endif
