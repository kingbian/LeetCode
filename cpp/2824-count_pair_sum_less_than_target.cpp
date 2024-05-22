#include <algorithm>
#include <vector>

using namespace std;

/*
 * Time Complexity: O(n log m); n-> time taken to sort the given vector
 * Space Complexity: O(1)
 */

int countPairs(vector<int> &nums, int target) {
  std::sort(nums.begin(), nums.end());

  int pair = 0, left = 0, right = nums.size() - 1;

  while (left < right) {

    if (nums[left] + nums[right] < target) {
      pair += right - left;
      left++;
    } else {
      right--;
    }
  }

  return pair;
}
