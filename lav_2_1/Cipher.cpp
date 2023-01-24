#include "modAlphaCipher.hpp"
#include <iostream>
modAlphaCipher::modAlphaCipher(const std::string& skey, const std::string&dictionary)
{
 numAlpha = dictionary;
 for (unsigned i=0; i < numAlpha.size(); i++) {
 alphaNum[numAlpha[i]] = i;
 }
 key = convert(getValidKey(skey));
}
std::string modAlphaCipher::encrypt(const std::string& open_text)
{
 std::vector<int> work = convert(getValidOpenText(open_text));
 for (unsigned i=0; i < work.size(); i++) {
 work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
 }
 return convert(work);
}
std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
 std::vector<int> work = convert(getValidCipherText(cipher_text));
 for (unsigned i=0; i < work.size(); i++) {
 work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
 }
 return convert(work);
}
inline std::vector<int> modAlphaCipher::convert(const std::string& s)
{
 std::vector<int> result;
 for (auto c:s) {
 result.push_back(alphaNum[c]);
 }
 return result;
}
inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{
 std::string result;
 for (auto i:v) {
 result.push_back(numAlpha[i]);
 }
 return result;
}
std::string modAlphaCipher::generateDict()
{
 char* dictionary = new char[34];
 char a = 0xc0;
 for (size_t i = 0; i < 6; i++)
 {
 dictionary[i] = a;
 a++;
 }
 dictionary[6] = 0xA8;
 for (size_t i = 7; i < 33; i++)
 {
 dictionary[i] = a;
 a++;
 }
 dictionary[33] = '\0';
 std::string s_dictionary = std::string(dictionary);
 delete[] dictionary;
 dictionary = nullptr;
 return s_dictionary;
}
inline std::string modAlphaCipher::getValidKey(const std::string& s)
{
 if (s.empty())
 throw cipher_error("Empty key");
 std::string tmp(s);
 for (auto& c:tmp) {
 if (!(((int)c > -65 && (int)c < 0) || ((int)c == -88) || ((int)c == -72)))
 throw cipher_error(std::string("Invalid key ") + s);
 if (((int)c > -33 && (int)c < 0) || ((int)c == -72)) {
 if ((int)c == -72)
 c = char(-88);
 else
 c = char((int)c-32);
 }
 }
 return tmp;
}
inline std::string modAlphaCipher::getValidOpenText(const std::string& s)
{
 std::string tmp;
 for (auto c:s) {
 if (((int)c > -65 && (int)c < 0) || ((int)c == -88) || ((int)c == -72))
 if(((int)c > -33 && (int)c < 0) || ((int)c == -72))
 if ((int(c) == -72))
 tmp.push_back(char((int)c-16));
 else
 tmp.push_back(char((int)c-32));
 else
 tmp.push_back(c);
 }
 if (tmp.empty())
 throw cipher_error("Empty open text");
 return tmp;
}
inline std::string modAlphaCipher::getValidCipherText(const std::string& s)
{
 if (s.empty())
 throw cipher_error("Empty cipher text");
 for (auto c:s)
 if (!(((int)c > -65 && (int)c < -32) || ((int)c == -88)))
 throw cipher_error(std::string("Invalid cipher text ")+s);
 return s;
}
