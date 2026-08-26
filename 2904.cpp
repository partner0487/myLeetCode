#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int head = 0, cnt1 = 0, n = s.length();
        string res = "";
        for (int tail = 0; tail < n; tail++)
        {
            if (s[tail] == '1')
                cnt1++;
            while (cnt1 == k)
            {
                if (s[head] == '1')
                {
                    string sub = s.substr(head, tail - head + 1);
                    if (res.empty() ||
                        sub.length() < res.length() ||
                        (sub.length() == res.length() && sub < res))
                        res = sub;
                    cnt1--;
                }
                head++;
            }
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "100011001";
    int k = 3;

    string res = sol.shortestBeautifulSubstring(s, k);
    cout << res;
}
// 1 10 100 1000 10001 100011