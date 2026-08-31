#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int len = 1; len <= n / 2; len++)
        {
            if (n % len)
                continue;
            string tmp(s, 0, len), ans;
            bool state = true;
            for (int j = 0; j < n; j += len)
            {
                if (s.substr(j, len) != tmp)
                {
                    state = false;
                    break;
                }
            }
            if (state)
                return true;
        }
        return false;
    }
};

/* 暴力 O(n^2)
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int len = 1; len <= n / 2; len++)
        {
            if (n % len)
                continue;
            string tmp(s, 0, len), ans;
            bool state = true;
            for (int j = 0; j < n; j += len)
            {
                if (s.substr(j, len) != tmp)
                {
                    state = false;
                    break;
                }
            }
            if (state)
                return true;
        }
        return false;
    }
};
*/

int main()
{
    Solution sol;
    string s = "abab";
    bool ans = sol.repeatedSubstringPattern(s);
    cout << ans;
}