#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> umap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (c != umap[top])
                    return false;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
int main()
{
    Solution sol;
    string s = "()[]{}";
    bool ans = sol.isValid(s);
    cout << ans;
}