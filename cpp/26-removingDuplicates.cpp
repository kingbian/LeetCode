#include <iostream>
#include <vector>

using namespace std;

int removingDuplicates(vector<int>& nums) {
    
    int track =0; 

    for(int i =0; i<nums.size(); i++){

        if(nums[track] != nums[i]){
            track++;
        }

        nums[track]= nums[i];
    }
 
  return track+1;
}

int main() {
  vector<int> nums{1,1,1,1,1,1,2};

  cout << removingDuplicates(nums) << endl;
}