#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int x = clamp(xCenter,x1,x2);
        int y = clamp(yCenter,y1,y2);
        return (x-xCenter) * (x-xCenter) + (y-yCenter) * (y-yCenter) <= radius * radius;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    int radius, xCenter, yCenter, x1, y1, x2, y2;

    bool res = sol.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);
    cout << res;
}
