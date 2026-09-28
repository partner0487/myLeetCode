#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cur = 0;
        for (auto c : s) {
            if (c == '(') 
                ans = max(ans, ++cur);
            if (c == ')')
                cur--;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";

    int output = sol.maxDepth(s);
    cout << output;
}