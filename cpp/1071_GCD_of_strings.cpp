#include <iostream>
#include <numeric>
#include <string>

std::string gcdOfString(std::string str1, std::string str2) {
    if (str1 + str2 != str2 + str1) {
        return "";
    }
    int gcdLength = std::gcd(str1.size(), str2.size());
    return str1.substr(0, gcdLength);
}
