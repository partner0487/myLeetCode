#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        int k = total_sum % p;
        if (!k)
            return 0;

        unordered_map<int, int> last_idx;
        last_idx[0] = -1;
        int cur_mod = 0;
        int min_len = n;

        for (int i = 0; i < n; ++i)
        {
            cur_mod = (cur_mod + nums[i]) % p;

            int target = (cur_mod - k + p) % p;

            if (last_idx.count(target))
                min_len = min(min_len, i - last_idx[target]);

            last_idx[cur_mod] = i;
        }

        return min_len == n ? -1 : min_len;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;

    int output = sol.minSubarray(nums, p);
    cout << output;
}