#include <iostream>
#include <limits>
#include "src/lib/routeCipher.hpp"
int main()
{
 std::string key;
 std::string text;
 unsigned op;
 std::cout << "Key: ";
 std::cin >> key;
 try {
 routeCipher cipher(key);
 do {
 std::cout<<"Operation (0-exit, 1-encrypt, 2-decrypt): ";
 std::cin>>op;
 if (op > 2) {
 std::cout<<"Illegal operation\n";
 } else if (op >0) {
 std::cout<<"Text: ";
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
'\n');
 std::getline(std::cin, text);
 if (op==1) {
 std::cout<< "Encrypted text: " << cipher.encrypt(text)
<<std::endl;
10
 } else {
 std::cout<< "Decrypted text: " << cipher.decrypt(text)
<<std::endl;
 }
 }
 } while (op!=0);
 } catch(cipher_error& e) {
 std::cerr << "Error: " << e.what() << std::endl;
 }
 return 0;
}
