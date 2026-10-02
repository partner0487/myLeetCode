#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1]; });
        int res = 0;
        int n = intervals.size();
        int maxright = -1;
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][1] > maxright)
            {
                res++;
                maxright = intervals[i][1];
            }
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> input = {{1, 4}, {1, 2}, {3, 4}};

    int output = sol.removeCoveredIntervals(input);
    cout << output;
}