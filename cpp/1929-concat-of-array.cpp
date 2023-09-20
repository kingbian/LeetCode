#include <iostream>
#include <vector>

using namespace std;


vector<int> getConcatenation(vector<int>&nums){
    int size= nums.size();
    
    for(int i=0; i <size; ++i){

        nums.push_back(nums[i]);
    }

    
    return nums;
    
}


int main(){

    vector<int> nums{1,3,2,1};

    for(const int& i: getConcatenation(nums)){
        cout<<i<<",";
    }

    cout<<endl;
}