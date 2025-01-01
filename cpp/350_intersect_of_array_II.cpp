#include <unordered_map>
#include <vector>

using namespace std;

/* vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    int size1 = nums1.size();
    int size2 = nums2.size();

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (nums1[i] == nums2[j] && nums2[j] != -1) {
                nums2[j] = -1;
                ans.push_back(nums1[i]);
                break;
            }
        }
    }

    return ans;
} */

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    vector<int> ans;
    for (auto ele : nums1) {
        map[ele]++;
    }

    for (auto ele : nums2) {
        if (map[ele] > 0)
            ans.push_back(ele);
        map[ele]--;
    }

    return ans;
}
