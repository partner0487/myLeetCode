#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    string cur = "";
    void dfs(int n, int left, int right)
    {
        if (cur.length() == 2 * n)
        {
            ans.push_back(cur);
            return;
        }
        if (left < n)
        {
            cur.push_back('(');
            dfs(n, left + 1, right);
            cur.pop_back();
        }
        if (right < left)
        {
            cur.push_back(')');
            dfs(n, left, right + 1);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);
    for (auto s : ans)
        cout << s << endl;
}