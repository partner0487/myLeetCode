#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 1; i < nums.size(); i++)
        {
            int tmp = nums[i - 1];
            while (++tmp < nums[i])
                res.push_back(tmp);
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {1, 4, 2, 5};

    vector<int> output = sol.findMissingElements(input);
    for (auto i : output)
    {
        cout << i;
    }
}
