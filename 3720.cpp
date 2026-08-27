#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string lexGreaterPermutation(string s, string target)
    {
        int n = s.length(), match_len = 0;
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        vector<int> cnt_now = cnt;
        while (match_len < n && cnt_now[target[match_len] - 'a'] > 0)
        {
            cnt_now[target[match_len] - 'a']--;
            match_len++;
        }

        for (int i = match_len; i >= 0; i--)
        {
            vector<int> rem_cnt = cnt;
            for (int j = 0; j < i; ++j)
                rem_cnt[target[j] - 'a']--;

            if (i == n)
                continue;

            for (int cnum = target[i] - 'a' + 1; cnum < 26; cnum++)
            {
                if (rem_cnt[cnum] > 0)
                {
                    string ans = target.substr(0, i);
                    ans += (char)('a' + cnum);
                    rem_cnt[cnum]--;
                    for (int ch = 0; ch < 26; ++ch)
                    {
                        while (rem_cnt[ch] > 0)
                        {
                            ans += (char)('a' + ch);
                            rem_cnt[ch]--;
                        }
                    }
                    return ans;
                }
            }
        }
        return "";
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "abc";
    string target = "bba";

    string res = sol.lexGreaterPermutation(s, target);
    cout << res;
}