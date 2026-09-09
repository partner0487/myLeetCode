#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (long long base = 1000; base <= n; base *= 1000)
            ans += (n - base + 1);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    long long n = 1002;

    long long res = sol.countCommas(n);
    cout << res << endl;
}
