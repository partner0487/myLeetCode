#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        int n = nums.size();
        int ans = 0, left = 0;
        for (int right = 0; right < n; right++)
        {
            umap[nums[right]]++;
            while (umap[nums[right]] > k)
                umap[nums[left++]]--;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;
    int ans = sol.maxSubarrayLength(nums, k);
    cout << ans;
}