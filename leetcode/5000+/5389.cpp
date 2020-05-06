#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        // customerNamei,tableNumberi,foodItemi
        // table, map<foodItem, set<customerName>>
        map<int, map<string, set<string>>> tables;
        set<string> foods;
        for (vector<string> order : orders) {
            tables[stoi(order[1])][order[2]].insert(order[0]);
            foods.insert(order[2]);
        }

        vector<vector<string>> ans;

        // 第一行
        vector<string> firstLine = {"Table"};
        map<string, int> foodNameIndex;  // map 加速定位食物对应的位置
        int idx = 1;
        for (auto food : foods) {
            firstLine.push_back(food);
            foodNameIndex[food] = idx++;
        }
        ans.push_back(firstLine);

        // 求每一桌
        for (auto table : tables) {  // 对于每一桌
            vector<string> line(firstLine.size(), "0");
            line[0] = to_string(table.first);
            for (auto food : table.second) {  // 对于每一种食品
                idx = foodNameIndex[food.first];
                line[idx] = to_string(food.second.size());
            }
            ans.push_back(line);
        }

        return ans;
    }
};

int main() {}