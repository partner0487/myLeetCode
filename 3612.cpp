#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string processStr(string s)
    {
        string res;
        for (auto i : s)
        {
            switch (i)
            {
            case '#':
                res += res;
                break;
            case '%':
                reverse(res.begin(), res.end());
                break;
            case '*':
                if (!res.empty())
                    res.pop_back();
                break;
            default:
                res += i;
                break;
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
    string input = "a#b%*";

    string res = sol.processStr(input);
    cout << res;
}
