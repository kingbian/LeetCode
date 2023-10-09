#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums){

    int sum = nums.at(0), size = nums.size(); 
    for(int i =1; i<size; ++i){
        sum+=nums[i]; 
        nums[i] +=sum; 

        
    }

    return nums;
}

