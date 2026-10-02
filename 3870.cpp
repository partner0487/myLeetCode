#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCommas(int n)
    {
        if (n < 1000)
            return 0;
        return n - 1000 + 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    int n = 1002;

    int res = sol.countCommas(n);
    cout << res << endl;
}
