#include <limits.h>
#include <iostream>
#include <ctype.h>
#include <algorithm>
int myAtoi(std::string s)
{
    int i;
    long ans;
    ans = i = 0;
    bool isNegative = false;
    // std::cout << "return here";

    while (i < s.size() && s[i] == ' ')
        ++i; // ignore all white space ans zerso

    if (s[i] == '-' && i < s.size())
    {
        isNegative = true;
        ++i;
    }
    else if (s[i] == '+' && i < s.size())
    {
        ++i;
    }

    while (i < s.size() && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10))
        {
            return (isNegative) ? INT_MIN : INT_MAX;
        }

        ans = (ans * 10) + digit;
        ++i;
    }
    return (isNegative) ? -ans : ans;
}

int main()
{

    std::cout << myAtoi("2147483648") << "\n";

    return 0;
}