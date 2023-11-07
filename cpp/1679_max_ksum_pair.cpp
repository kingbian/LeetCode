#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxOperations(vector<int> &nums, int k)
{

    sort(nums.begin(), nums.end());

    int start = 0, end = nums.size() - 1, operations = 0;

    while (start < end)
    {

        if (nums[start] + nums[end] > k)
        {
            end--;
        }
        else if (nums[start] + nums[end] < k)
        {
            start++;
        }
        else
        {
            operations++;
            start++; 
            end--;
        }
    }
    return operations;
}

/**
 * unordered map 
*/

int max( vector<int>& nums, int k){

    int count =0;
    unordered_map<int, int> map; 

    for(int i =0; i<nums.size(); ++i){
        
        int comp = k-nums[i]; 

        if(map[comp]){
            count++; 
            map[comp]--; 
        }else{
            map[nums[i]]++; 
        }

    }

    return count; 

}
