#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int cnt[26] = {};
        int ans = 0, head = 0, tail = 0;
        while (tail < s.length())
        {
            cnt[s[tail] - 'a']++;
            while (cnt[s[tail] - 'a'] > 2)
                cnt[s[head++] - 'a']--;
            ans = max(ans, tail - head + 1);
            tail++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "bcbbbcba";
    int ans = sol.maximumLengthSubstring(s);
    cout << ans;
}