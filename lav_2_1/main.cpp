#include <iostream>
#include <cctype>
#include "src/lib/modAlphaCipher.hpp"
#include "Windows.h"
using namespace std;
int main(int argc, char **argv)
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 std::string dictionary = modAlphaCipher::generateDict();
 string key;
 string text;
 unsigned op;
 cout<<"Cipher ready. Input key: ";
 cin>>key;
 try {
 modAlphaCipher cipher(key, dictionary);
 do {
 cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
 cin>>op;
 if (op > 2) {
 cout<<"Illegal operation\n";
 } else if (op > 0) {
 cout<<"Cipher ready. Input text: ";
 cin>>text;
 if (op == 1) {
 cout<<"Encrypted text:
"<<cipher.encrypt(text)<<endl;
 } else {
 cout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
 }
 }
 } while (op!=0);
 }
 catch(const cipher_error& e) {
 cerr << "Error: " << e.what() << endl;
 }
 return 0;
}
