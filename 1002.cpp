#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        int minfreq[26];
        for (auto i = 0; i < 26; i++)
            minfreq[i] = INT_MAX;
        for (auto i : words)
        {
            int freq[26] = {};
            for (auto j : i)
                freq[j - 'a']++;
            for (auto k = 0; k < 26; k++)
                minfreq[k] = min(minfreq[k], freq[k]);
        }

        vector<string> res;
        for (auto i = 0; i < 26; i++)
            for (int j = 0; j < minfreq[i]; j++)
                res.push_back(string(1, 'a' + i));

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<string> input = {"bella", "label", "roller"};

    vector<string> output = sol.commonChars(input);
    cout << "[\"" << output[0] << "\"";
    for (auto i = 1; i < output.size(); i++)
    {
        cout << ",\"" << output[i] << "\"";
    }
    cout << "]";
}
