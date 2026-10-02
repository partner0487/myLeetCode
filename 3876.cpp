#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int mini = *min_element(nums1.begin(), nums1.end());
        if (mini % 2)
            return true;
        for (auto num : nums1)
            if (num % 2)
                return false;
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 4, 7};
    bool ans = sol.uniformArray(nums);
    cout << ans;
}