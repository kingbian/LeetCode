#include <algorithm>
#include <vector>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0, j = m; i < nums2.size(); ++i, j++) {
        nums1[j] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}
