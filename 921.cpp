#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, right = 0;
        for (auto c : s) {
            if (c == '(')
                left++;
            else if (left > 0)
                left--;
            else
                right++;
        }
        return left + right;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = ")(";

    int output = sol.minAddToMakeValid(s);
    cout << output << endl;
}
