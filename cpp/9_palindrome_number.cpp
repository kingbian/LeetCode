#include <iostream>

bool isPalindrome(int x)
{
    // base case
    if (x < 0)
        return false;

    long ans = 0;
    int original = x;
    while (x != 0)
    {
        int r = x % 10;

        ans = (ans * 10) + r; // multiply by 10 to shift digits to the left by 1 (adding space ) ans = 1*10 --> 10 + r

        x = x / 10;
    }

    if (original == ans)
        return true;

    return false;
}

int main()
{

    std::cout << std::boolalpha;
    std::cout << isPalindrome(1234567899) << "\n";

    return 0;
}