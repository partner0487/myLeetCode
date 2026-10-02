#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int cur = 0;
        vector<int> ans;
        for (auto c : seq)
        {
            if (c == ')')
                cur--;
            ans.push_back(cur % 2);
            if (c == '(')
                cur++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string seq = "(()())";
    vector<int> ans = sol.maxDepthAfterSplit(seq);
    for (auto i : ans)
        cout << i << " ";
}