#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;
class modTableCipher
{
private:
 int key;
 string getValidText(const string & s);
public:
 modTableCipher()=delete;
 modTableCipher(const int& key){}; 
 string encrypt(const string& open_text); 
 string decrypt(const string& cipher_text); 
};
class cipher_error: public std::invalid_argument
{
public:
 explicit cipher_error (const string& what_arg):
 std::invalid_argument(what_arg) {}
 explicit cipher_error (const char* what_arg):
 std::invalid_argument(what_arg) {}
};
