#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            } else if (arr[mid] < arr[right]) {
                right = mid;
            } else {
                right--;
            }
        }

        int res = find(arr, target, 0, left - 1);
        if (res != -1) return res;
        return find(arr, target, left, arr.size() - 1);
    }

    int find(vector<int>& arr, int target, int left, int right) {
        int i = left, j = right;
        int res = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            // cout << i << " " << j << " " << mid << endl;
            if (arr[mid] == target) {
                res = mid;
                j = mid - 1;
            } else if (arr[mid] > target) {  //在左侧
                j = mid - 1;
            } else {  // 在右侧
                i = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    cout << s.search(v, 0);
}