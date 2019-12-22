#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, area = 0;
        while(i<j){
            int h = min(height[i], height[j]);
            area = max(area, h*(j-i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return area;
    }
};

int main(){
    Solution solution;
    // 1,8,6,2,5,4,8,3,7
    vector<int> v;
    v.push_back(1);
    v.push_back(8);
    v.push_back(6);
    v.push_back(2);
    v.push_back(5);
    v.push_back(4);
    v.push_back(8);
    v.push_back(3);
    v.push_back(7);

    cout << solution.maxArea(v);
}