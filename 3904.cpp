#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> v;
        int maxm = 0, mini = INT_MAX;
        for (int i = n - 1; i > -1; i--)
        {
            mini = min(mini, nums[i]);
            v.push_back(mini);
        }
        for (int i = 0; i < n; i++)
        {
            maxm = max(maxm, nums[i]);
            if (maxm - v[n - 1 - i] <= k)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;
    int ans = sol.firstStableIndex(nums, k);
    cout << ans;
}