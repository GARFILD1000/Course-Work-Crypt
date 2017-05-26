#ifndef VIGENERECRYPT_H
#define VIGENERECRYPT_H
int WordToKey(int key[], char word[]);
int CheckSymbolLang(int symbol);
int VigenereCryptProcessing(int symbol, int key_symbol);
void StackFilesPath(char filename[], int InOrOut);
int VigenereCrypt(char word[]);
void VigenereWindow();
void ShowMessage(int result);
#endif
