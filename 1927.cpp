#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.length();
        int sumDiff = 0, qDiff = 0;
        for (int i = 0; i < n; i++)
        {
            if (num[i] == '?')
                i < n >> 1 ? qDiff++ : qDiff--;
            else
                i < n >> 1 ? sumDiff += (num[i] - '0') : sumDiff -= (num[i] - '0');
        }
        if (qDiff % 2 != 0)
            return true;
        return sumDiff * 2 != -qDiff * 9;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string input = "?3295???";

    bool output = sol.sumGame(input);
    cout << output;
}
