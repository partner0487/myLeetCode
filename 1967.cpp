#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int res = 0;
        for (auto i : patterns)
        {
            if (word.find(i) != string::npos)
                res++;
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<string> input = {"a", "abc", "bc", "d"};
    string word = "abc";

    int output = sol.numOfStrings(input, word);
    cout << output;
}
