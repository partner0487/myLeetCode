#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestIndex(vector<int> &nums)
    {
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0, tmp = nums[i];
            while (tmp)
            {
                sum += tmp % 10;
                tmp /= 10;
            }
            if (i == sum)
                return i;
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {1, 3, 2};

    int output = sol.smallestIndex(input);
    cout << output;
}
