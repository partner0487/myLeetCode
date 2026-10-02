#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;
        for (int index = 0; index < nums.size(); index++)
        {
            int complement = target - nums[index];
            if (umap.find(complement) != umap.end())
                return {umap[complement], index};
            umap[nums[index]] = index;
        }
        return {};
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> res = sol.twoSum(nums, target);
    for (auto &v : res)
    {
        cout << v << " ";
    }
}
