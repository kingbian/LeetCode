#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coutPairs(vector<int>& nums, int target){

    int pair =0,  size= nums.size();

    for(int i=0; i<size; ++i){

        for(int j=0; j<size; ++j){

            if(nums[i]+nums[j]<target && i<j){
                pair++;
            }
        }
    }

    return pair;
}

