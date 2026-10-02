#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length(), res = 0, head = 0;
        int arr[3] = {};
        for (int tail = 0; tail < n; tail++)
        {
            arr[s[tail] - 'a']++;
            while (arr[0] && arr[1] && arr[2])
            {
                res += n - tail;
                arr[s[head] - 'a']--;
                head++;
            }
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string input = "aaacb";

    int output = sol.numberOfSubstrings(input);
    cout << output;
}
