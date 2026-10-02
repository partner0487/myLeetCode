#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        int cnt[3] = {}, sum = 0, state = 0;
        for (auto stone : stones)
            cnt[stone % 3]++;
        if (!(cnt[0] % 2))
        {
            if (cnt[1] && cnt[2])
                return true;
            return false;
        }
        return abs(cnt[2] - cnt[1]) > 2;
    }
};

// 2 0 2 1 1 Bwin
// 2 2 1 2 1 0 Bwin
// 2 0 2 1 2 1 2 Bwin

int main()
{
    Solution sol;
    vector<int> nums = {1, 2};
    bool ans = sol.stoneGameIX(nums);
    cout << ans;
}