#include <iostream>
#include <vector>

using namespace std;
int searchInsert(vector<int>& nums, int target) {

	int low = 0, high = nums.size() - 1;

	while (low <= high) {

		int mid = low + (high - low) / 2;

		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] > target) {
			high = --mid;
		} else {
			low = ++mid;
		}
	}

	return low;
}

int main() {

	vector<int> nums{-1, 0, 3, 5, 9, 12};

	cout << searchInsert(nums, 2) << "sdsd" << endl;
	return 0;
}
