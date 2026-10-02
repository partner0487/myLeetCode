#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        int tmp = k;
        while (ranges::count(nums, tmp) != 0)
            tmp += k;
        return tmp;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {1, 4, 7, 10, 15};
    int k = 5;

    int res = sol.missingMultiple(input, k);
    cout << res;
}
