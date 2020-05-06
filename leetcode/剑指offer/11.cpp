#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty()) return -1;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return numbers[left];
        // 3, 4, 5, 1, 2
        //       m  l  r
        //          m  r
        //         l r
    }
};

int main() {}