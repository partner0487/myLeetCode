#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int leftsum=0,rightsum=0;
        for(auto num:nums){
            rightsum+=num;
        }
        for(auto num:nums){
            rightsum-=num;
            res.push_back(abs(rightsum-leftsum));
            leftsum+=num;
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> input = {10,4,8,3};

    vector<int> output = sol.leftRightDifference(input);
    cout << "[" << output[0];
    for (auto i = 1; i < output.size(); i++)
    {
        cout << "," << output[i];
    }
    cout << "]";
}
