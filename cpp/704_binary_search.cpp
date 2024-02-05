#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int start, end;

	start = 0;
	end = nums.size() - 1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] < target) {
			start = mid + 1;
		}

		if (nums[mid] > target) {
			end = mid - 1;
		}
	}

	return -1;
}

int main() {

	vector<int> nums{-1, 0, 3, 5, 9, 12};

	cout << search(nums, 9) << endl;
	return 0;
}