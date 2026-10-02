#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (ranges::count(ans, i) == 1)
                    continue;
                if (!mat[i][j])
                    ans.push_back(i);
                if (ans.size() == k)
                    return ans;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (ranges::count(ans, i) == 1)
                continue;
            ans.push_back(i);
            if (ans.size() == k)
                return ans;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> arr = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};
    int target = 3;

    vector<int> res = sol.kWeakestRows(arr, target);
    
}
