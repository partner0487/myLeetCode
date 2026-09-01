#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<string> &classroom, int energy)
    {
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = classroom.size(), n = classroom[0].length(), l_cnt = 0;
        int start_x = 0, start_y = 0;
        queue<tuple<int, int, int, int, int>> q; // { cnt, energy, mask, x, y }
        map<pair<int, int>, int> l_id;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (classroom[i][j] == 'S')
                {
                    start_x = i;
                    start_y = j;
                }
                if (classroom[i][j] == 'L')
                    l_id[{i, j}] = l_cnt++;
            }
        }
        if (l_cnt == 0)
            return 0;
        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1 << l_cnt, -1)));
        q.push({0, energy, 0, start_x, start_y});
        max_energy[start_x][start_y][0] = energy;
        while (!q.empty())
        {
            auto [now_cnt, now_energy, now_mask, x, y] = q.front();
            q.pop();
            if (now_energy < max_energy[x][y][now_mask])
                continue;
            if (now_energy == 0)
                continue;
            for (int i = 0; i < 4; i++)
            {
                int next_x = x + dir[i][0], next_y = y + dir[i][1],
                    next_energy = now_energy - 1, next_mask = now_mask;
                if (next_x >= m || next_x < 0 || next_y >= n || next_y < 0)
                    continue;
                if (classroom[next_x][next_y] == 'X')
                    continue;
                if (classroom[next_x][next_y] == 'L')
                    next_mask |= (1 << l_id[{next_x, next_y}]);
                if (classroom[next_x][next_y] == 'R')
                    next_energy = energy;
                if (next_mask == (1 << l_cnt) - 1)
                    return now_cnt + 1;
                if (next_energy > max_energy[next_x][next_y][next_mask])
                {
                    max_energy[next_x][next_y][next_mask] = next_energy;
                    q.push({now_cnt + 1, next_energy, next_mask, next_x, next_y});
                }
            }
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<string> input = {"S.", "XL"};
    int energy = 2;

    int output = sol.minMoves(input, energy);
    cout << output;
}
