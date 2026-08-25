#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int sum = 0, pd = 1, tmp = n;
        while (tmp)
        {
            sum += tmp % 10;
            pd *= (tmp % 10);
            tmp /= 10;
        }
        return n % (sum + pd) == 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    int k = 99;

    bool res = sol.checkDivisibility(k);
    cout << res;
}
