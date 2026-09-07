#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans(n, 0);
        for (int i = 0; i < n / 2; ++i)
        {
            ans[i] = -(i + 1);
            ans[n - 1 - i] = i + 1;
        }
        return ans;
    }
};

// -2 -1 0 1 2
// -2 -1 1 2

int main()
{
    Solution sol;
    int n = 0;
    vector<int> ans = sol.sumZero(n);
    for (auto num : ans)
        cout << num << ",";
}