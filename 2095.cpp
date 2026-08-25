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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head->next->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {1, 3, 4, 7, 1, 2, 6};
    ListNode *head = new ListNode(1);
    ListNode *now = head;
    for (auto i = 1; i < input.size(); i++)
    {
        ListNode *tmp = new ListNode(input[i]);
        now->next = tmp;
        now = tmp;
    }

    ListNode *res = sol.deleteMiddle(head);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
}
