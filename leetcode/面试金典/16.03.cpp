#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1,
                                vector<int>& start2, vector<int>& end2) {
        int ax1 = start1[0], ay1 = start1[1];
        int ax2 = end1[0], ay2 = end1[1];
        int bx1 = start2[0], by1 = start2[1];
        int bx2 = end2[0], by2 = end2[1];

        /*
            Ax + By + C = 0
            A = y2 - y1
            B = x1 - x2
            C = x2y1-x1y2
        */
        int A1 = ay2 - ay1;              // y2 - y1
        int B1 = ax1 - ax2;              // x2 - x1
        int C1 = ax2 * ay1 - ax1 * ay2;  // x2y1 - x1y2

        int A2 = by2 - by1;              // y2 - y1
        int B2 = bx1 - bx2;              // x2 - x1
        int C2 = bx2 * by1 - bx1 * by2;  // x2y1-x1y2

        /*
            如果两直线平行，则有 A1/B1 == A2/B2
            为了避免除零的问题，可转化为 A1*B2 == A2*B1
        */
        vector<pair<int, int>> points;
        if (A1 * B2 == A2 * B1) {  //如果平行
            // 判断直线b的起点是否在直线a上
            if (isPointInLine(ax1, ay1, ax2, ay2, bx1, by1)) {
                points.push_back({bx1, by1});
            }
            // 判断直线b的终点是否在直线a上
            if (isPointInLine(ax1, ay1, ax2, ay2, bx2, by2)) {
                points.push_back({bx2, by2});
            }
            // 判断直线a的起点是否在直线b上
            if (isPointInLine(bx1, by1, bx2, by2, ax1, ay1)) {
                points.push_back({ax1, ay1});
            }
            // 判断直线a的终点是否在直线b上
            if (isPointInLine(bx1, by1, bx2, by2, ax2, ay2)) {
                points.push_back({ax2, ay2});
            }
            if (!points.empty()) {
                sort(points.begin(), points.end(),
                     [](const pair<int, int> pa, const pair<int, int> pb) {
                         if (pa.first == pb.first) {
                             return pa.second < pb.second;
                         }
                         return pa.first < pb.first;
                     });
                return {(double)points[0].first, (double)points[0].second};
            }
        } else {
            /*
                首先设交点坐标为(x, y)，两线段对应直线的一般式为：
                a1x + b1y + c1 = 0
                a2x + b2y + c2 = 0
                那么对1式乘a2, 对2式乘a1得：
                a2*a1x + a2*b1y + a2*c1 = 0
                a1*a2x + a1*b2y + a1*c2 = 0

                y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1)
                x = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1)

                如果(x,y)在两线段上，则(x,y)即为答案，否则交点不存在
            */
            double x = (1.0 * C2 * B1 - C1 * B2) / (1.0 * A1 * B2 - A2 * B1);
            double y = (1.0 * C1 * A2 - C2 * A1) / (1.0 * A1 * B2 - A2 * B1);
            // 判断点 (x,y) 是否在直线 a、b 上
            if (isPointInLine(ax1, ay1, ax2, ay2, x, y) &&
                isPointInLine(bx1, by1, bx2, by2, x, y)) {
                return {x, y};
            }
        }
        return {};
    }

   private:
    const double EPS = 1e-7;
    bool isPointInLine(int x1, int y1, int x2, int y2, double px, double py) {
        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        double d1 = sqrt((px - x1) * (px - x1) + (py - y1) * (py - y1));
        double d2 = sqrt((px - x2) * (px - x2) + (py - y2) * (py - y2));
        if (fabs(d1 + d2 - d) <= EPS) return true;
        return false;
    }
};

int main() {}