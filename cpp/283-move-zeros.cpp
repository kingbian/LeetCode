#include <iostream>
#include <vector>

using namespace std;

void moveZeros(vector<int>& nums) {
  int lPtr = 0, length = nums.size();

  for (int i = 1; i < length; i++) {
    if (nums[i] != 0 && nums[lPtr] == 0) {
      int temp = nums[i];
      nums[i] = nums[lPtr];
      nums[lPtr++] = temp;
      /**
       * NOTE:use the swap function??
       */
    }

    if (nums[lPtr] != 0) {
      lPtr++;
    }
  }
}

int main() {
  vector<int> num{0, 0, 0, 00, 1};

  moveZeros(num);
}