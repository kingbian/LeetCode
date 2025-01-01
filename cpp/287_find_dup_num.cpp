#include <vector>

using namespace std;

/**
*
* Naive implemenation

* Time Complexity: O(n)
* Space Complexity: O(n) -> due to the number of elements be allocated
*
int findDuplicate(vector<int>& nums) {
    vector<bool> ans(nums.size(), false);

    for (auto ele : nums) {
        if (ans[ele] == false) {
            ans[ele] = true;
        } else {
            return ele;
        }
    }
    return -1;
}

* */

/**
 * using Flody's cycle detection algorithm
 * Time Complexity: O(n)
 * Space Complexity: O(1) -> constraint must use only 1 extra space
 *
 */

int findDuplicate(vector<int>& nums) {
    int slow = nums[nums[0]];
    int fast = nums[nums[nums[0]]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
