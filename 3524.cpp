#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> resultArray(vector<int> &nums, int k)
    {
        vector<long long> dp(k, 0), ans(k, 0);
        vector<long long> next_dp(k, 0);
        for (auto num : nums)
        {
            ranges::fill(next_dp, 0);
            int val = num % k;
            next_dp[val]++;
            ans[val]++;
            for (int j = 0; j < k; j++)
                if (dp[j] > 0)
                {
                    next_dp[(j * val) % k] += dp[j];
                    ans[(j * val) % k] += dp[j];
                }
            dp.swap(next_dp);
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {1, 2, 3, 4, 5};
    int k = 3;

    vector<long long> output = sol.resultArray(input, k);
    for (auto i : output)
    {
        cout << i << endl;
    }
}
