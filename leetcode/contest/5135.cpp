#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findBestValue(vector<int>& arr, int target) {
        // sort(arr.begin(), arr.end());

        int _min = arr[0];
        int _max = arr[0];
        int sum = 0;
        for (int i : arr) {
            sum += i;
            if (i < _min) _min = i;
            if (i > _max) _max = i;
        }

        if (sum <= target) {
            return _max;
        }

        int mean = sum / target + 0.5;
        if (_min >= mean) {
            return mean;
        }

        return 0;
    }
};

int main() {}