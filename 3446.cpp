#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> v(2 * n);
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[n - 1 + i - j].push_back(grid[i][j]);
        for (int i = 0; i < n - 1; i++)
            ranges::sort(v[i]);
        for (int i = n - 1; i < 2 * n - 1; i++)
            ranges::sort(v[i], greater{});
        for (int i = n - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                ans[i][j] = v[n - 1 + i - j].back();
                v[n - 1 + i - j].pop_back();
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> input = {{0, 1, 0}, {1, 1, 0}, {0, 1, 0}};

    vector<vector<int>> output = sol.sortMatrix(input);
    for (auto i : output)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
