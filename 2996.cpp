#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int i = 0, ans = nums[0];
        while (++i < nums.size() && nums[i - 1] == nums[i] - 1)
            ans += nums[i];
        unordered_set<int> uset(nums.begin(), nums.end());
        while (uset.count(ans))
            ans++;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 7, 6, 6, 5, 8, 2, 8, 9, 2, 6};
    int ans = sol.missingInteger(nums);
    cout << ans;
}