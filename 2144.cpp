#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int last = cost.size() - 1;
        sort(cost.begin(), cost.end());
        int sum = 0;
        for (int i = last; i >= 0; i -= 3)
        {
            if (i == 0)
                sum += cost[0];
            else
                sum += cost[i - 1] + cost[i];
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> cost = {6, 5, 7, 9, 2, 2}; // 2+5 7+9

    int res = sol.minimumCost(cost);
    cout << res;
}
