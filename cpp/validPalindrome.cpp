#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) {
      return true;
    }
    string copyStr;
    for (int i = 0; i < s.length(); ++i) {
      if (isalnum(s[i])) {
        s[i] = tolower(s[i]);
        copyStr += s[i];
      }

     
    }
    s.erase();
    s = copyStr;

    reverse(copyStr.begin(), copyStr.end());
    cout << copyStr << endl;
    int ans = copyStr.compare(s);
    if (ans == 0) {
      return true;
    }

    return false;
  }
};

int main() {
  Solution s;
  cout << boolalpha;
  bool ans = s.isPalindrome("......a.....");
  cout << ans << endl;
}