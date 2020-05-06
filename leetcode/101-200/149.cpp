#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // int gcd(int a, int b) {
    //     if (a == 0) return b;
    //     if (b == 0) return a;
    //     if (a % 2 == 0 && b % 2 == 0)
    //         return 2 * gcd(a >> 1, b >> 1);
    //     else if (a % 2 == 0)
    //         return gcd(a >> 1, b);
    //     else if (b % 2 == 0)
    //         return gcd(a, b >> 1);
    //     else
    //         return gcd(abs(a - b), min(a, b));
    // }

    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    vector<int> bestLine(vector<vector<int>>& points) {
        int gSize = -1;    // 通过某条直线的最大点数
        int p0 = INT_MAX;  // 前2个点的位置
        int p1 = INT_MAX;

        for (int i = 0; i < points.size(); i++) {
            vector<int> dup;              // 重复的点
            int innerMax = 0;             // 通过某条直线的最大点数
            int innerMaxIndex = INT_MAX;  // 最小的位置
            map<string, vector<int>> mm;  // 斜率 -> 位置集

            for (int j = i + 1; j < points.size(); j++) {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];

                if (x == 0 && y == 0) {  // 重复的点
                    dup.push_back(j);
                    continue;
                }

                string key = "";
                if (x == 0) {  // 没有斜率
                    key = "0";
                } else if (y == 0) {  //斜率为0
                    key = "1";
                } else {  // 存在斜率
                    int g = gcd(abs(x), abs(y));
                    if (x < 0 && y < 0) {
                        x = -x;
                        y = -y;
                    } else if (x < 0 || y < 0) {
                        x = -abs(x);
                        y = abs(y);
                    }
                    key = to_string(y / g) + "/" + to_string(x / g);
                }
                mm[key].push_back(j);

                // 更新第二个点
                vector<int> t = mm[key];
                if (t.size() > innerMax) {
                    innerMax = t.size();
                    innerMaxIndex = t[0];
                } else if (innerMax == t.size() && t[0] < innerMaxIndex) {
                    innerMaxIndex = t[0];
                }
            }

            if (innerMax == 0) {  // 都是重复的点
                if (dup.size() + 1 > gSize) {
                    gSize = dup.size() + 1;
                    p0 = i;
                    p1 = dup[0];
                } else if (dup.size() + 1 == gSize) {
                    if ((i < 0) || (i == 0 && dup[0] < p1)) {
                        p0 = i;
                        p1 = dup[0];
                    }
                }
            } else {
                // 重复的点的最小值可能小于 innerMaxIndex
                if (!dup.empty()) innerMaxIndex = min(innerMaxIndex, dup[0]);
                innerMax = innerMax + dup.size() + 1;
                if (innerMax > gSize) {
                    gSize = innerMax;
                    p0 = i;
                    p1 = innerMaxIndex;
                } else if (innerMax == gSize) {
                    if ((i < p0) || (i == p0 && innerMaxIndex < p1)) {
                        p0 = i;
                        p1 = innerMaxIndex;
                    }
                }
            }
        }
        vector<int> ans = {p0, p1};
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {
        {-13260, 8589},   {1350, 8721},     {-37222, -19547}, {-54293, -29302},
        {-10489, -13241}, {-19382, 574},    {5561, 1033},     {-22508, -13241},
        {-1542, 20695},   {9277, 2820},     {-32081, 16145},  {-50902, 23701},
        {-8636, 19504},   {-17042, -28765}, {-27132, -24156}, {-48323, -4607},
        {30279, 29922}};
    Solution s;
    vector<int> res = s.bestLine(points);
    cout << res[0] << " " << res[1];
}
