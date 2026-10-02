#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vec(26,0);
        for(auto c:word){
            vec[c-'a']++;
        }
        sort(vec.rbegin(), vec.rend());
        int ans = 0, count = 1;
        for(int i=0;i<26;i++){
            ans+=vec[i]*((i / 8) + 1);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string word = "aabbccddeeffgghhiiiiii";
    int ans = sol.minimumPushes(word);
    cout<<ans;
}