#include <iostream>
#include <vector>

using namespace std;

void show(vector<int>& path) {
    for (int i : path) cout << i << " ";
    cout << endl;
}

void test(vector<int>& nums, int index, vector<int>& path) {
    if (path.size() == 3) show(path);

    for (int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        test(nums, i + 1, path);
        path.pop_back();
    }
}

int main() {
    vector<int> path;
    vector<int> nums = {1, 2, 3, 4, 5};
    test(nums, 0, path);
}