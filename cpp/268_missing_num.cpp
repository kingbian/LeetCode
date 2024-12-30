#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    vector<bool> ans(nums.size() + 1, false);

    for (auto ele : nums) {
        ans[ele] = true;
    }

    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == false) {
            return i;
        }
    }
    return -1;
}
