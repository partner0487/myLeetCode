#include <bits/stdc++.h>
using namespace std;

// dp[i][m]= max(dp[i][m],sums[i] - dp[i + x][max(m, x)])
class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> sum = piles;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 2; i >= 0; --i)
            sum[i] += sum[i + 1];
        for (int i = 0; i < n; ++i) {
            dp[i][n] = sum[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int m = n - 1; m >= 1; --m) {
                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    dp[i][m] = max(dp[i][m], sum[i] - dp[i + x][max(m, x)]);
                }
            }
        }
        return dp[0][1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 9, 4, 4};
    int ans = sol.stoneGameII(nums);
    cout << ans;
}