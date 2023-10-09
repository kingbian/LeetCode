#include <iostream>
#include <vector>

using namespace std;

int numIdenticalPairs(vector<int> &nums)
{

    int pair = 0, size = nums.size();

    for (int i = 0; i < size; ++i)
    {

        for(int j =0; j< size; ++j)
        if (nums[i] == nums[j] && i<j)
        {
            pair++;
        }
    }

    return pair; 
}