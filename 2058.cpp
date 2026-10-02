#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev = head;
        int first_dir = 0, prev_dir = 0, now_dir = 1, minDistance = INT_MAX;
        while (prev && prev->next && prev->next->next)
        {
            int prev_val = prev->val,
                now_val = prev->next->val,
                next_val = prev->next->next->val;
            if ((now_val < next_val && now_val < prev_val) || (now_val > next_val && now_val > prev_val))
            {
                if (!first_dir)
                    first_dir = now_dir;
                else
                    minDistance = min(minDistance, now_dir - prev_dir);
                prev_dir = now_dir;
            }
            now_dir++;
            prev = prev->next;
        }
        if (minDistance == INT_MAX)
            return {-1, -1};
        return {minDistance, prev_dir - first_dir};
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {1, 3, 2, 2, 3, 2, 2, 2, 7};
    ListNode *head = new ListNode(1);
    ListNode *now = head;
    for (auto i = 1; i < input.size(); i++)
    {
        ListNode *tmp = new ListNode(input[i]);
        now->next = tmp;
        now = tmp;
    }

    vector<int> res = sol.nodesBetweenCriticalPoints(head);
    for (auto i : res)
    {
        cout << i << " ";
    }
}
