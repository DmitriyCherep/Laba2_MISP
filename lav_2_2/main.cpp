#include "modTableCipher.h"
#include <string>
using namespace std;
void check(const string& Text, const string& key)
{
 try {
 string cipherText;
 string decryptedText;
 if (key.empty())
 throw cipher_error("Empty key");
 if (stoi(key) > 0) {
 modTableCipher cipher(stoi(key));
 cipherText = cipher.encrypt(Text);
 decryptedText = cipher.decrypt(cipherText);
 cout<<"key="<<key<<endl;
 cout<<"Encrypted text: "<<cipherText<<endl;
 cout<<"Decrypted text: "<<decryptedText<<endl;
 } else
 throw cipher_error(string("Invalid key ")+key);
 } catch (const cipher_error & e) {
 cerr<<"Error: "<<e.what()<<endl;
 }
 cout<<""<<endl;
}
int main(int argc, char **argv)
{
 check("error handling","0");
 check("error handling","");
 check("error handling","cod");
}
