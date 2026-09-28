#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')') {
                int left = st.top();
                st.pop();
                reverse(&s[left], &s[i]);
            }
        }
        string ans = "";
        for (char c : s) {
            if (c != '(' && c != ')')
                ans += c;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "(abcd)"; 

    string output = sol.reverseParentheses(s);
    cout << output;
}