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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> BT;
        unordered_map<int, bool> child_set;
        for (auto description : descriptions)
        {
            if (BT.find(description[0]) == BT.end())
            {
                TreeNode *node = new TreeNode();
                node->val = description[0];
                BT[description[0]] = node;
                child_set[description[0]] = false;
            }
            if (BT.find(description[1]) == BT.end())
            {
                TreeNode *child = new TreeNode();
                child->val = description[1];
                BT[description[1]] = child;
            }

            child_set[description[1]] = true;

            if (description[2])
                BT[description[0]]->left = BT[description[1]];
            else
                BT[description[0]]->right = BT[description[1]];
        }
        
        int root;
        for (auto it = child_set.begin(); it != child_set.end(); it++)
        {
            if (!it->second){
                root = it->first;
                break;
            }
        }
        return BT[root];
    }
};

void levelorder(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "空樹" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size(); // 當前這一層的節點數量

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *curr = q.front();
            q.pop();

            cout << curr->val << " ";

            // 如果有左子節點，放入佇列
            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            // 如果有右子節點，放入佇列
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
        cout << endl; // 換行，方便肉眼看出每一層的結構
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> input = {{39, 70, 1}, {13, 39, 1}, {85, 74, 1}, {74, 13, 1}, {38, 82, 1}, {82, 85, 1}};

    TreeNode *root = sol.createBinaryTree(input);

    levelorder(root);
}
