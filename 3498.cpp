#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseDegree(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans += (26 - s[i] + 'a') * (i + 1);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "abc";

    int output = sol.reverseDegree(s);
    cout << output;
}
