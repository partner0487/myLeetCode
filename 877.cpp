#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size(), e = 0, o = 0;
        for (int i = 0; i < n; i += 2)
        {
            e += piles[i];
            o += piles[i + 1];
        }

        return e != o;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {5, 3, 4, 5};

    bool output = sol.stoneGame(input);
    cout << output;
}