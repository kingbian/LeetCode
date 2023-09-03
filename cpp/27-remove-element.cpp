#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int removeElement(vector<int>& nums, int val){
    for(int i=nums.size()-1; i>=0; i--){

        if(nums[i] == val){
           nums.erase(nums.begin()+i);
        }


    }

    return nums.size(); 
}


int main(){

    vector<int> nums{0,1,2,2,3,0,4,2};

    cout<<removeElement(nums, 2);
}