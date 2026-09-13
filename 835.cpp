#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        vector<pair<int, int>> img1_one, img2_one;
        int cnt[59][59] = {}, max_match = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j] == 1)
                {
                    img1_one.push_back({i, j});
                    for (auto [x2, y2] : img2_one)
                    {
                        int dx = i - x2 + 29;
                        int dy = j - y2 + 29;
                        max_match = max(max_match, ++cnt[dx][dy]);
                    }
                }
                if (img2[i][j] == 1)
                {
                    img2_one.push_back({i, j});
                    for (auto [x1, y1] : img1_one)
                    {
                        int dx = x1 - i + 29;
                        int dy = y1 - j + 29;
                        max_match = max(max_match, ++cnt[dx][dy]);
                    }
                }
            }
        }
        return max_match;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}}, img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};

    int output = sol.largestOverlap(img1, img2);
    cout << output;
}