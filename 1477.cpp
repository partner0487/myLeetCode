#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        int left = 0, sum = 0, ans = INT_MAX;
        for (int right = 0; right < n; right++)
        {
            sum += arr[right];
            while (sum > target)
                sum -= arr[left++];
            if (right > 0)
                min_len[right] = min_len[right - 1];
            if (sum == target)
            {
                int cur_len = right - left + 1;
                if (left > 0 && min_len[left - 1] != INT_MAX)
                    ans = min(ans, cur_len + min_len[left - 1]);
                min_len[right] = min(min_len[right], cur_len);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> arr = {3, 2, 2, 4, 3};
    int target = 3;

    int res = sol.minSumOfLengths(arr, target);
    cout << res;
}
