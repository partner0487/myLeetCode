#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// O(n)
class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size(), res = -1;
        if (k >= n)
            return ranges::max(nums);
        unordered_map<int, int> umap;
        for (int x : nums)
            umap[x]++;
        if (k == 1)
        {
            for (auto [x, cnt] : umap)
                if (cnt == 1)
                    res = max(res, x);
            return res;
        }
        if (umap[nums[0]] == 1)
            res = nums[0];
        if (umap[nums[n - 1]] == 1)
            res = max(res, nums[n - 1]);
        return res;
    }
};

/* O(nk)
class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        int n = nums.size(), res = -1;
        for (int i = 0; i <= n - k; i++)
        {
            unordered_set<int> uset;
            for (int j = i; j < i + k; j++)
                uset.insert(nums[j]);
            for (auto num : uset)
                umap[num]++;
        }
        for (auto it : umap)
            if (it.second == 1)
                res = max(it.first, res);
        return res;
    }
};
*/

int main()
{
    Solution sol;
    vector<int> nums = {3, 9, 2, 1, 7};
    int k = 3;
    int ans = sol.largestInteger(nums, k);
    cout << ans;
}