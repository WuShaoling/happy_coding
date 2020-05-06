#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MountainArray {
   public:
    int get(int index);
    int length();
};

class Solution {
   public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // 求峰值的位置
        int left = 0, right = mountainArr.length() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        mid = left;

        // 在上升数组中查找
        int ans = find1(target, mountainArr, 0, mid);
        if (ans != -1) return ans;

        // 直接返回在下降数组中查找的结果
        return find2(target, mountainArr, mid + 1, mountainArr.length() - 1);
    }

    int find1(int target, MountainArray &mountainArr, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int midV = mountainArr.get(mid);
            if (midV == target) return mid;
            if (midV < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int find2(int target, MountainArray &mountainArr, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int midV = mountainArr.get(mid);
            if (midV == target) return mid;
            if (midV < target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {}