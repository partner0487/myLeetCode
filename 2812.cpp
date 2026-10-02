#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        // 建立危險地圖
        // n^2 次 BFS X，從所有 1 出發做 BFS O
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c])
                {
                    q.push({r, c});
                    grid[r][c] = 0;
                    visit[r][c] = true;
                }
            }
        }

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int rn = r + dir[i][0];
                int cn = c + dir[i][1];

                if (rn < 0 || rn >= n || cn < 0 || cn >= n)
                    continue;

                if (visit[rn][cn])
                    continue;

                q.push({rn, cn});
                visit[rn][cn] = true;
                grid[rn][cn] = grid[r][c] + 1;
            }
        }

        // 找safest最大的路
        int res = grid[0][0];
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visit_s(n, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty())
        {
            int path_min = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r == n - 1 && c == n - 1)
                return path_min;
            if (visit_s[r][c])
                continue;
            visit_s[r][c] = true;
            for (int i = 0; i < 4; i++)
            {
                int rn = r + dir[i][0];
                int cn = c + dir[i][1];

                if (rn < 0 || rn >= n || cn < 0 || cn >= n)
                    continue;
                if (visit_s[rn][cn])
                    continue;

                int next_path_min = min(path_min, grid[rn][cn]);
                pq.push({next_path_min, {rn, cn}});
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
    vector<vector<int>> input = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};

    int output = sol.maximumSafenessFactor(input);
    cout << output;
}
