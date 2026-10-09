#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        int left = 0, right = 0, prev_right = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                right += 2;
                if (right % 2 == 1)
                {
                    prev_right++;
                    right--;
                }
            }
            else
            {
                right--;
                if (right < 0)
                {
                    left++;
                    right = 1;
                }
            }
        }
        return left + prev_right + right;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = ")())(";

    int output = sol.minInsertions(s);
    cout << output;
}