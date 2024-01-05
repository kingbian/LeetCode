#include <functional>
#include <iostream>
#include <map>

std::string intToRoman(int num) {

  /**
   * use std::greater<int> to reverse the order of the ordered map
   *
   **/
  std::map<int, std::string, std::greater<int>> map{

      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"},

  };

  std::string ans;

  /**
   * go through the map, getting the quotient of num/key
   * example: quotient = 1994/1000 --> 1 meaning theres 1 1000's that go into
   * 1994
   */
  for (const auto &pair : map) {
    // std::cout << "int : " << pair.first << " roman: " << pair.second << "\n";
    int quotient = num / pair.first;

    if (quotient) { // quotient != 0

      // add quotient * pair[key] to the answer
      for (int i = 0; i < quotient; ++i) {
        ans += pair.second;
      }
    }

    num %= pair.first;
  }

  return ans;
}

int main() {

  std::cout << intToRoman(1994) << "\n";

  return 0;
}
