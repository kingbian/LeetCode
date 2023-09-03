#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
  int start = 0;
  int end = needle.length() - 1;

  int counter = 0;
  for (int i = 0; i < haystack.length(); ++i) {
    if (counter == end) {
      cout << "returned" << endl;
      cout << "i: " << i << "counter: " << counter << endl;
      
      return i - counter;  // index
    }
    if (haystack[i] == needle[start]) {
      cout << "found" << endl;
      counter++;
    }

    if (counter > needle.length()) {
      cout << "sd" << endl;
      counter = 0;
    }

    if (start == end) {
      start = 0;
    }
  }

  return -1;
}

int main() {
  string hay = "sadbutsad";
  string ned = "sad";

  cout << strStr(hay, ned) << endl;
}