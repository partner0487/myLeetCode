#include <bits/stdc++.h>
using namespace std;

// Manacher’s Algorithm
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        string t = "$#";
        for (char ch : s)
        {
            t += ch;
            t += "#";
        }
        t += "&";

        int n = t.length();
        vector<int> palindrome_radius(n, 0);
        int center = 0, right = 0;
        int maxlen = 0, lps_center = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int mirror = 2 * center - i;
            if (right > i)
                palindrome_radius[i] = min(right - i, palindrome_radius[mirror]);
            else
                palindrome_radius[i] = 1;

            while (t[i + palindrome_radius[i]] == t[i - palindrome_radius[i]])
                palindrome_radius[i]++;

            if (i + palindrome_radius[i] > right)
            {
                center = i;
                right = i + palindrome_radius[i];
            }

            if (palindrome_radius[i] > maxlen)
            {
                maxlen = palindrome_radius[i];
                lps_center = i;
            }
        }
        int start = (lps_center - maxlen) / 2;
        return s.substr(start, maxlen - 1);
    }
};

/* DP
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, max_len = 1;
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = i; j < n; j++)
            {
                dp[i][j] = (s[i] == s[j]) && ((j - i <= 2) || dp[i + 1][j - 1]);

                if (dp[i][j] && (j - i + 1) > max_len)
                {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
    }
};
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "a";

    string res = sol.longestPalindrome(s);
    cout << res;
}
