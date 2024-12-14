#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> stack;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stack.push(s[i]);

        } else {
            if (stack.empty()) {
                return false;
            }
            auto top = stack.top();

            if (!stack.empty() && (top == '(' && s[i] == ')') || (top == '{' && s[i] == '}') || (top == '[' && s[i] == ']')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }

    return stack.empty();
}
