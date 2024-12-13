#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisapperedNumbers(vector<int>& nums) {
    vector<bool> seenElements(nums.size() + 1, false);  // initial with range from [1,n] (1 based range)
    vector<int> ans;                                    // vector to hold all unseen ints

    for (auto num : nums) {
        seenElements[num] = true;
    }

    for (int i = 1; i < seenElements.size(); i++) {
        if (seenElements[i] == false)
            ans.push_back(i);
    }

    return ans;
}

int main() {
    vector<int> input = {1, 1};

    for (auto i : findDisapperedNumbers(input)) {
        cout << i << ", ";
    }

    cout << endl;
}
