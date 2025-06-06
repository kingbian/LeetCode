#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int maxArea(vector<int> &height) {
  int ans = 0, left = 0, right = height.size() - 1, area = 0;
  int height_measure, width;

  while (left <= right) {

    // get the width
    width = right - left;
    // get the smaller height
    height_measure = min(height[left], height[right]);
    area = width * height_measure;
    ans = max(ans, area);
    // move the pointers
    if (height[left] < height[right]) {
      left++;

    } else {
      right--;
    }
  }
  return ans;
}
