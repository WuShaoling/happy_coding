#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

class Solution {
public:
    int findClosestElements(vector<int> &arr, int k, int x) {
        cout << x;
        int pos = -1;
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                pos = x;
                break;
            } else if (arr[mid] > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return pos;
    }
};

int main() {
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    Solution solution;
    cout << solution.findClosestElements(arr, 0, 5);
}
