#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
 try {
 wstring cipherText;
 wstring decryptedText;
 modAlphaCipher cipher(key);
 cipherText = cipher.encrypt(Text);
 decryptedText = cipher.decrypt(cipherText);
 wcout<<L"key="<<key<<endl;
 wcout<<Text<<endl;
 wcout<<cipherText<<endl;
 wcout<<decryptedText<<endl;
 } catch (const cipher_error & e) {
 wcerr<<"Error: "<<e.what()<<endl;
 }
}
int main()
{
 locale loc("ru_RU.UTF-8");
 locale::global(loc);
 check(L"ОБРАБОТКАИСКЛЮЧЕНИЙ",L"КОД");
 check(L"Обработкаисключений",L"");
 check(L"обработкаисключений",L"код");
 check(L"",L"код");
 return 0;
}
