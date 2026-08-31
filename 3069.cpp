#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; i++)
            arr1.back() > arr2.back() ? arr1.push_back(nums[i])
                                      : arr2.push_back(nums[i]);
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 9, 2, 1, 7};
    vector<int> ans = sol.resultArray(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
}