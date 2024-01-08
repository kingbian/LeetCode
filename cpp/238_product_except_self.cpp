#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums)
{

    int size = nums.size();

    std::vector<int> ans(size);

    std::vector<int> forward(size);
    std::vector<int> backwards(size);

    int previous = 1;
    for (int i = 0; i < size; ++i)
    {
        forward[i] = previous;
        previous *= nums[i];
    }

    previous = 1;
    for (int i = size - 1; i >= 0; --i)
    {
        backwards[i] = previous;
        previous *= nums[i];
    }

    for (int i = size - 1; i >= 0; --i)
    {

        ans[i] = forward[i] * backwards[i];
    }

    return ans;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4};
    for (auto &i : productExceptSelf(nums))
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";
}