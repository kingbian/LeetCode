#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int lengthOfLastString(string s) {

	int count = 0, end = s.size() - 1;

	while (end >= 0 && s[end] == ' ') {
		end--;
	}

	while (end >= 0 && s[end] != ' ') {
		count++;
		end--;
	}

	return count;
}

int main() {

	string test = "a    ";

	cout << lengthOfLastString(test);
	return 0;
}
