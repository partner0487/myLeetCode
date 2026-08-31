#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0, cnt = -1;
        for (auto num : nums)
            res ^= num;
        if(res) return n;
        for (auto num : nums){
            if(num)
                return n-1;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 4};
    int ans = sol.longestSubsequence(nums);
    cout << ans;
}