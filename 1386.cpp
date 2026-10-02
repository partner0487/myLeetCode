#include <bits/stdc++.h>
using namespace std;

// bitmask
class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, uint8_t> umap;
        for (const auto& seat : reservedSeats)
        {
            if (seat[1] == 1 || seat[1] == 10)
                continue;
            umap[seat[0]] |= (1 << (seat[1] - 2));
        }
        constexpr uint8_t group[3] = {0b00001111,
                                      0b00111100,
                                      0b11110000};
        int mapn = umap.size();
        int res = 2 * (n - mapn);
        for (const auto& it : umap)
            if (!(it.second & group[0]) || !(it.second & group[1]) || !(it.second & group[2]))
                res++;
        return res;
    }
};

/*
class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, unordered_set<int>> umap;
        for (auto seat : reservedSeats)
        {
            if (seat[1] == 1 || seat[1] == 10)
                continue;
            umap[seat[0] - 1].insert(seat[1]);
        }
        int arr[3][4] = {{2, 3, 4, 5}, {4, 5, 6, 7}, {6, 7, 8, 9}};
        int mapn = umap.size();
        int res = 2 * (n - mapn);
        for (auto it : umap)
        {
            bool state[3] = {true, true, true};
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 4; k++)
                    if (it.second.count(arr[j][k]))
                        state[j] = false;
            if (state[0] && state[2])
                res += 2;
            else if (state[0] || state[1] || state[2])
                res++;
        }
        return res;
    }
};
*/

int main()
{
    Solution sol;
    vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    int n = 3;
    int ans = sol.maxNumberOfFamilies(n, reservedSeats);
    cout << ans;
}