#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0, max_open = 0;
        for (auto c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else {
                min_open--;
                max_open++;
            }
            if (max_open < 0)
                return false;
            min_open = max(min_open, 0);
        }
        return min_open == 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "(*))";

    bool output = sol.checkValidString(s);
    cout << output;
}