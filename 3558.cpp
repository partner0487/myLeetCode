#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        int n = 0;
        for (const auto &edge : edges)
        {
            n = max({n, edge[0], edge[1]});
        }
        n += 1;

        vector<vector<int>> umap(n);
        vector<int> in_degree(n, 0);
        int max_depth = 0;
        for (auto node : edges)
        {
            umap[node[0]].push_back(node[1]);
            in_degree[node[1]]++;
        }
        int root = 1;
        while (in_degree[root] != 0)
            root++;

        queue<pair<int, int>> qe;
        qe.push(make_pair(root, -1));
        while (!qe.empty())
        {
            pair<int, int> top = qe.front();
            qe.pop();
            for (auto i : umap[top.first])
            {
                qe.push(make_pair(i, top.second + 1));
                max_depth = max(max_depth, top.second + 1);
            }
        }

        int ans = 1;
        int mod = 1e9 + 7;
        for (int i = 0; i < max_depth; i++)
            ans = ans * 2 % mod;
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> input = {{2, 3}, {1, 2}};

    int output = sol.assignEdgeWeights(input);
    cout << output;
}
