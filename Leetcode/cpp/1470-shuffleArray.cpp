#include <iostream>
#include <vector>
using namespace std;

// brute force
/*
vector<int> shuffle(vector<int>& nums, int n) {
  vector<int> x;
  vector<int> y;
  vector<int> result;
  result.reserve(nums.size());
  int i = 0;

  for (; i < n; i++) {
     cout<<"Val at "<<i<< ": "<<nums[i]<<endl;
    x.push_back(nums[i]);
  }

  for (; i < nums.size(); i++) {
    cout<<"Val at "<<i<< ": "<<nums[i]<<endl;
    y.push_back(nums[i]);
  }

  for (int j = 0; j < n; j++) {
    result.push_back(x[j]);
    result.push_back(y[j]);
  }

  return result;
}

*/


/*O(n) time complexity*/


vector<int> shuffle(vector<int>& nums, int n){
    vector<int> result;
    int s=n;// get the second half of vector

    for(int i=0; i<n; i++ ){
        result.push_back(nums[i]);
        result.push_back(nums[s++]);
    }

    return result;

}





signed main() {
  vector<int> nums{1, 2, 3, 4, 4, 3, 2, 1};

  for (const int& i : shuffle(nums, 4)) { 
    cout << i << ",";
  }
  cout << "\n";
