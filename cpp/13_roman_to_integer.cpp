#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>
#include <cstdlib>
using namespace std;

int romans(string s)
{

    std::unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int ans = 0;
    int perviousVal = 0;
    for (int i = 0; i < s.length(); ++i)
    {

        char element = s[i];

        int currentVal = map.find(element)->second;

        if (perviousVal < currentVal)
        {
            int newVal = currentVal - perviousVal;
            ans += newVal - perviousVal;
        }
        else
        {
            ans += currentVal;
        }
        perviousVal = currentVal;
    }

    return ans;
}

int main()
{

    int ans = romans("MCMXCIV");
    cout << ans << "\n";
    return 0;
}