#include "routeCipher.hpp"
#include <algorithm>
#include <string>
routeCipher::routeCipher(const std::string& key)
{
 columns = std::stoi(getValidKey(key));
}
std::string routeCipher::encrypt(const std::string& str)
{
 int rows = div_up(getValidOpenText(str).size(), columns);
 std::vector<std::vector<char>> table;
 for (int i = 0; i < rows; i++) {
 table.emplace_back(std::vector<char>());
 }
 int charCount = 0;
 int tableSize = columns * rows;
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < columns; j++) {
 // if (charCount < str.size()) {
 table[i].push_back(str[charCount]);
 charCount++;
 // }
 // else {
 // table[i].push_back(' ');
 // charCount++;
 // }
 }
 }
 std::string result;
 for (int i = 0; i < rows; i++)
 {
 std::reverse(table[i].begin(), table[i].end());
 for (int j = 0; j < table[i].size(); j++) {
 result.push_back(table[i][j]);
 }
 }
 result.erase(std::remove(result.begin(), result.end(), '\0'),result.end());
 return result;
}
std::string routeCipher::decrypt(const std::string& str)
{
 int rows = div_up(getValidCipherText(str).size(), columns);
 std::vector<std::vector<char>> table;
 for (int i = 0; i < rows; i++) {
 table.emplace_back(std::vector<char>());
 }
 int charCount = 0;
 int tableSize = columns * rows;
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < columns; j++) {
 // if (charCount < str.size()) {
 table[i].push_back(str[charCount]);
 charCount++;
 // }
 // else {
 // table[i].push_back(' ');
 // charCount++;
 // }
 }
 }
 std::string result;
 for (int i = 0; i < rows; i++)
 {
 std::reverse(table[i].begin(), table[i].end());
 for (int j = 0; j < table[i].size(); j++) {
 result.push_back(table[i][j]);
 }
 }
 result.erase(std::remove(result.begin(), result.end(), '\0'),
result.end());
 return result;
}
int routeCipher::div_up(int x, int y)
{
 return (x - 1) / y + 1;
9
}
inline std::string routeCipher::getValidKey(const std::string& s)
{
 if (s.empty())
 throw cipher_error("Empty key");
 std::string tmp(s);
 for (auto& c:tmp) {
 if (!((int)c > 47 && (int)c < 58) || (s == "0"))
 throw cipher_error(std::string("Invalid key ") + s);
 }
 return tmp;
}
inline std::string routeCipher::getValidOpenText(const std::string& s)
{
 std::string tmp;
 for (auto c:s)
 if ((int)c > 31 && (int)c < 127)
 tmp.push_back(c);
 if (tmp.empty())
 throw cipher_error("Empty open text");
 return tmp;
}
inline std::string routeCipher::getValidCipherText(const std::string& s)
{
 std::string tmp;
 for (auto c:s)
 if ((int)c > 31 && (int)c < 127)
 tmp.push_back(c);
 if (tmp.empty())
 throw cipher_error("Empty cipher text");
 return tmp;
}
