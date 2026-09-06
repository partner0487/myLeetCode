#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = m; j > 0; j--)
                if (s[i - 1] == t[j - 1])
                    dp[j] += dp[j - 1];
        return (int)dp[m];
    }
};

/*
r 1 0 0 0 0 0
a 1 1 0 0 0 0
b 1 1 1 0 0 0
b 1 1 2 1 0 0
b 1 1 3 3 0 0
i 1 1 3 3 3 0
t 1 1 3 3 3 3
*/

int main()
{
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    int ans = sol.numDistinct(s, t);
    cout << ans;
}