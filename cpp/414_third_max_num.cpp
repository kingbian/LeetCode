#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
int thirdMax(std::vector<int>& nums) {

	set<int> orderedSet(nums.begin(), nums.end());

	if (orderedSet.size() < 3) {
		auto it = orderedSet.end();
		return *(--it);
	}

	int thirdMaxIndex = orderedSet.size() - 3;

	auto it = next(orderedSet.begin(), thirdMaxIndex);

	return *it;
}
