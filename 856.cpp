#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, cnt = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                cnt++;
            else {
                if (s[i - 1] == '(') // 只有 "()" 才是最內層的
                    ans += pow(2, cnt);
                cnt--;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "()";

    int output = sol.scoreOfParentheses(s);
    cout << output;
}