#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) &&
               max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};

/*
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int rec1_left = rec1[0], rec1_bottom = rec1[1], rec1_right = rec1[2],
            rec1_top = rec1[3], rec2_left = rec2[0], rec2_bottom = rec2[1],
            rec2_right = rec2[2], rec2_top = rec2[3];
        if (rec1_left < rec2_left && rec1_right <= rec2_left)
            return false;
        if (rec1_bottom < rec2_bottom && rec1_top <= rec2_bottom)
            return false;
        if (rec1_right > rec2_right && rec1_left >= rec2_right)
            return false;
        if (rec1_top > rec2_top && rec1_bottom >= rec2_top)
            return false;
        return true;
    }
};
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> rec1 = {0, 0, 1, 1}, rec2 = {1, 0, 2, 1};

    bool output = sol.isRectangleOverlap(rec1, rec2);
    cout << output;
}