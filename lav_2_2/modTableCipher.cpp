#include "modTableCipher.h"
using namespace std;
string modTableCipher::decrypt(const string& cipher_text)
{
 string text = cipher_text;
 int length, lineQUA, position, i;
9
 length = cipher_text.size(); 
 lineQUA = (length - 1) / key+ 1; 
 i = 0;
 for (int columNUM = key; columNUM > 0; columNUM--) { 
 for (int lineNUM = 0; lineNUM < lineQUA; lineNUM++) {
 position = key*lineNUM+columNUM; 
 if (position-1 < length) {
 text[position-1] = cipher_text[i];
 i++;
 }
 }
 }
 return text;
}
string modTableCipher::encrypt(const string& open_text) 
{
 string text = open_text;
 int length, lineQUA, position, i;
 length = open_text.size();
 lineQUA = (length - 1) / key + 1;
 i = 0;
 for (int columNUM = key; columNUM > 0; columNUM--) {
 for (int lineNUM = 0; lineNUM < lineQUA; lineNUM++) {
 position = columNUM+key*lineNUM;
 if (position-1 < length) {
 text[i] = open_text[position-1];
 i++;
 }
 }
 }
 return text;
}
inline string modTableCipher::getValidText(const std::string
& s)
{
 string tmp;
 for (auto c:s) {
 if (isalpha (c)) {
 if (islower (c))
 tmp.push_back(toupper(c));
 else
 tmp.push_back(c);
 }
}
if (tmp.empty())
 throw cipher_error ("Empty open text");
 return tmp;
}
string modTableCipher::encrypt(const string& open_text) 
{
 string text = open_text;
 int length, lineQUA, position, i;
 length = open_text.size();
 lineQUA = (length - 1) / key + 1; 
 i = 0;
 for (int columNUM = key; columNUM > 0; columNUM--) {
 for (int lineNUM = 0; lineNUM < lineQUA; lineNUM++) {
 position = columNUM+key*lineNUM;
 if (position-1 < length) {
 text[i] = open_text[position-1];
 i++;
 }
 }
 }
 return text;
} 
