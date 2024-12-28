#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    int size = nums1.size();
    int size2 = nums2.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (nums1[i] == nums2[j]) {
                if (count(ans.begin(), ans.end(), nums1[i]) > 0) {
                    continue;
                }
                ans.push_back(nums1[i]);
                break;
            }
        }
    }

    return ans;
}
