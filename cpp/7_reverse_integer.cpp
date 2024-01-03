#include <iostream>
#include <cmath>
#include <limits.h>

/**very slow*/
int reverse(int x)
{

    std::string ans;
    if (x == 0 || x > __INT_MAX__ || x <= INT_MIN)
    {
        return 0;
    }

    try
    {

        if (x < 0)
        {
            x = abs(x);

            while (x != 0)
            {

                ans += std::to_string(x % 10);
                x = x / 10;
            }
            int result = std::stoi(ans);

            return -1 * result;
        }

        while (x != 0)
        {

            ans += std::to_string(x % 10);
            x = x / 10;
        }

        int result = std::stoi(ans);
        return result;
    }
    catch (...)
    {

        return 0;
    }
}

int reverse_fast(int x)
{

    /**
     * x = -321
     * remainder = -321 % 10 --> -1
     * ans = 0 *10 + remainder --> -1
     * x = -321 /10 --> -32
     * remainder = -32 % 10 --> -2
     * ans = 1 * 10 + 2 --> -12
     * x = -32 /10 --> -3
     * remainder = -3 % 10 --> -3
     * ans = -12 * 10 + -3 --> -123
     * x = -3/10 --> 0
     * break loop x == 0
     */

    int ans, remainder;
    ans = remainder = 0;

    while (x)
    {

        remainder = x % 10;

        if (ans < INT_MIN / 10 || ans > INT_MAX / 10)
            return 0;
        ans = ans * 10 + remainder;
        x /= 10;
    }

    return ans;
}

int main()
{
    using namespace std;
    int num = 0;

    cout << __INT_MAX__ << "\n";
    cin >> num;
    cout << reverse_fast(num) << "\n";

    return 0;
}