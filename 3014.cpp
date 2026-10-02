#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int t = n/8, k=n%8;
        return t?(4*t+k)*(t+1):k;
    }
};

int main(){
    Solution sol;
    string word = "abhrlngxyjkezwcm";
    int ans = sol.minimumPushes(word);
    cout<<ans;
}