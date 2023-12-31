#include <iostream>
#include <unordered_map>
#include <string>

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

    // auto printPrintKeyValue = [](const char& key, const int& value){

    //     std::cout<<"key: "<<key<<" value: "<<value<<"\n";
    // };

    // std::cout<<"printing unordered map\n";
    // for(const auto& [key, value] : map){
    //     printPrintKeyValue(key, value);
    // }

    int ans = 0;
    int perviousVal = 0;
    for (int i = 0; i < s.length(); ++i)
    {

        char element = s[i];
        // std::cout << element;

        int currentVal = map.find(element)->second;

        if (perviousVal < currentVal)
        {
            int newVal = currentVal - perviousVal;
            // std::cout << "current value for element : " << element << " newVal: " << newVal << "\n";
            ans += newVal - perviousVal;
        }
        else
        {
            // std::cout << "current value for element : " << element << " value: " << currentVal << "\n";
            ans += currentVal;
        }
        perviousVal = currentVal;
    }

    // std::cout << ans << "\n";

    return ans;
}

int main()
{

    int ans = romans("MCMXCIV");
    cout << ans << "\n";
    return 0;
}