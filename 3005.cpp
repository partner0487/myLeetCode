#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int n = nums.size(), max_cnt = 0;
        vector<int> ans, cnt(101, 0);
        for (auto num : nums)
        {
            if (++cnt[num] > max_cnt)
            {
                max_cnt = cnt[num];
                ans.clear();
            }
            if (cnt[num] == max_cnt)
                ans.push_back(num);
        }
        return ans.size() * max_cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    int ans = sol.maxFrequencyElements(nums);
    cout << ans;
}