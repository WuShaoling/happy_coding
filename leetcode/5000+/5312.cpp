#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int sum = 0;

        int i = 0;
        for (; i < k; i++) sum += arr[i];
        if (sum / k >= threshold) res++;

        for (; i < arr.size(); i++) {
            sum = sum + arr[i] - arr[i - k];
            if (sum / k >= threshold) res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {7, 7, 7, 7, 7, 7, 7};
    cout << s.numOfSubarrays(arr, 7, 7);
}