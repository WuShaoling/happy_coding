#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        for (int i = 0; i < arr.size(); i++) visited.push_back(false);
        return helper(arr, start);
    }

    bool helper(vector<int>& arr, int i) {
        if (i < 0 || i >= arr.size() || visited[i]) return false;
        if (arr[i] == 0) return true;
        visited[i] = true;
        if (helper(arr, i + arr[i])) return true;
        if (helper(arr, i - arr[i])) return true;
        visited[i] = false;
        return false;
    }

    vector<bool> visited;
};

int main() {
    Solution s;
    vector<int> arr = {3, 0, 2, 1, 2};
    cout << s.canReach(arr, 2);
}