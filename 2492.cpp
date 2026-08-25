#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        int res = INT_MAX;
        queue<int> q;
        vector<vector<pair<int, int>>> grid(n + 1);
        vector<bool> visit(n + 1, false);

        // 從 1 出發做 BFS
        for (auto road : roads)
        {
            grid[road[0]].push_back({road[1], road[2]});
            grid[road[1]].push_back({road[0], road[2]});
        }

        q.push(1);
        visit[1] = true;
        while (!q.empty())
        {
            int r = q.front();
            q.pop();
            for (auto adj : grid[r])
            {
                res = min(res, adj.second);
                if (visit[adj.first])
                    continue;
                q.push(adj.first);
                visit[adj.first] = true;
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
    vector<vector<int>> input = {{1, 2, 9}, {2, 3, 6}, {1, 4, 7}, {2, 4, 5}};
    int n = 4;

    int output = sol.minScore(n, input);
    cout << output;
}