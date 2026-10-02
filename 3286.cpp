#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        pq.push({health - grid[0][0], {0, 0}});
        while (!pq.empty())
        {
            int now_health = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (!now_health)
                continue;
            if (r == m - 1 && c == n - 1)
                return true;
            if (visit[r][c])
                continue;
            visit[r][c] = true;
            for (int i = 0; i < 4; i++)
            {
                int rn = r + dir[i][0];
                int cn = c + dir[i][1];

                if (rn < 0 || rn >= m || cn < 0 || cn >= n)
                    continue;
                if (visit[rn][cn])
                    continue;

                pq.push({now_health - grid[rn][cn], {rn, cn}});
            }
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> input = {{0, 1, 0}, {1, 1, 0}, {0, 1, 0}};
    int health = 2;

    bool output = sol.findSafeWalk(input, health);
    cout << output;
}
/*
0 1 0
1 1 0
0 1 0
*/
