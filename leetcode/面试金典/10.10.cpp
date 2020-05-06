#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class StreamRank {
   public:
    StreamRank() {}

    void track(int x) {
        nums.push_back(x);
        // 插入排序
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }

    int getRankOfNumber(int x) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

   private:
    vector<int> nums;
};

int main() {}