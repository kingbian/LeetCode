#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  int track = 0, maxlength = 0, count = 0;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] - nums[count] == 1) {
      track++;
      if (track > maxlength) {
        maxlength = track;
      }
    } else {
      track = 0;
    }
    count++;
  }

  return maxlength + 1;
}

int main() {
  vector<int> nums{100, 4, 200, 1, 3, 2};

  cout << longestConsecutive(nums) << endl;
}