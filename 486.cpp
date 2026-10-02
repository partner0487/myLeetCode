#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }
        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i + k < n; i++)
            {
                int j = i + k;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {1, 5, 2};
    int n = 4;

    bool output = sol.predictTheWinner(input);
    cout << output;
}