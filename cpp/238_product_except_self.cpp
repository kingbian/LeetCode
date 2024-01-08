#include <iostream>
#include <vector>

std::vector<int> productExceptSelf_slow(std::vector<int> &nums)
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

/**
 * optimize to use O(1) extra space
 */
std::vector<int> productExceptSelf_fast(std::vector<int> &nums)
{

    int size = nums.size();
    std::vector<int> ans(size);

    ans[0] = 1;
    for (int i = 1; i < size; ++i)
    {
        ans[i] = nums[i - 1] * ans[i - 1];
    }

    int previous = 1;
    for (int i = size - 2; i >= 0; --i)
    {
        previous *= nums[i + 1];
        ans[i] *= previous;
    }

    return ans;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4};

    for (auto &i : productExceptSelf_slow(nums))
    {
        std::cout << i << ", ";
    }

    std::cout << "\n\n";
    for (auto &i : productExceptSelf_fast(nums))
    {
        std::cout << i << ", ";
    }
    std::cout
        << "\n";
}