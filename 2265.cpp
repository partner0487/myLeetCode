#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans = 0;
    pair<int, int> dfs(TreeNode *node)
    {
        if (node == nullptr)
            return {0, 0};
        int num = node->val;
        auto [l, lcnt] = dfs(node->left);
        auto [r, rcnt] = dfs(node->right);
        if ((l + r + num) / (lcnt + rcnt + 1) == num)
            ans++;
        return {l + r + num, lcnt + rcnt + 1};
    }

    int averageOfSubtree(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {4, 8, 5, 0, 1, -1, 6};
    TreeNode *root = new TreeNode(4);

    int res = sol.averageOfSubtree(root);
    cout << res << " ";
}
