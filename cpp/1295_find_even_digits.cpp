#include <iostream>
#include <vector>


using namespace std; 
int nums( vector<int>& nums){

    int evenNums=0; 
    for (int i =0; i< nums.size(); ++i){
        int a = nums[i], track =0; 
        while(a > 0){
            a= a/10;
            track++;
        }

        if(track%2 ==0){
            evenNums++;
        }
    }

    return evenNums; 
}

