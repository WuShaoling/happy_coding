#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canMeasureWater(int x, int y, int z) {
        map<pair<int, int>, bool> visited;
        queue<pair<int, int>> s;
        int remain_x, remain_y, _min;
        pair<int, int> p;

        s.push({0, 0});
        visited[{0, 0}] = true;
        while (!s.empty()) {
            pair<int, int> top = s.front();
            s.pop();
            remain_x = top.first;
            remain_y = top.second;

            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }

            // 把 X 壶灌满
            p = {x, remain_y};
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }

            // 把 Y 壶灌满
            p = {remain_x, y};
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }

            // 把 X 清空
            p = {0, remain_y};
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }

            // 把 Y 清空
            p = {remain_x, 0};
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }

            // 把 X 倒入 Y
            _min = min(remain_x, y - remain_y);
            p = {remain_x - _min, remain_y + _min};
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }

            // 把 Y 倒入 X
            _min = min(remain_y, x - remain_x);
            p = {remain_x + _min, remain_y - _min};
            if (!visited[p]) {
                s.push(p);
                visited[p] = true;
            }
        }
        return false;
    }
};

int main() {}