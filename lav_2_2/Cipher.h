#pragma once
#include <vector>
#include <string>
#include <stdexcept>
class routeCipher
{
 private:
 int columns;
 int div_up(int x, int y);
 std::string getValidKey(const std::string& s);
 std::string getValidOpenText(const std::string& s);
 std::string getValidCipherText(const std::string& s);
 public:
 routeCipher()=delete;
 routeCipher(const std::string& key);
 std::string encrypt(const std::string& open_text);
 std::string decrypt(const std::string& cipher_text);
};
class cipher_error: public std::invalid_argument {
 public:
 explicit cipher_error (const std::string& what_arg):
 std::invalid_argument(what_arg) {}
 explicit cipher_error (const char* what_arg):
 std::invalid_argument(what_arg) {}
};
