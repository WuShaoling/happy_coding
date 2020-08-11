#include <iostream>
#include <vector>
using namespace std;

/*
查找3
0 1 2 3 4 5 6
1 2 4 4 5 6
    lr
*/
/*
下界：
当一个元素存在时返回它出现的第一个位置
如果不存在，返回一个下标k，在此处插入元素，原来的元素都往后挪，序列仍然有序
*/
int lower_bound(const vector<int> &nums, int target) {
    // [)
    int left = 0, right = nums.size(), mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            // 如果相等，前面可能还有，继续往前 [left, mid)
            right = mid;
        } else if (nums[mid] > target) {
            // 如果当前值大于目标元素，则在前面搜 [left, mid)
            right = mid;
        } else if (nums[mid] < target) {
            // 小于说明要往后搜 [mid+1, right)
            left = mid + 1;
        }
    }
    return left;
}

/*
搜索5
0 1 2 3 4 5 6
1 2 3 5 5 5
        l m lr

上界：
当元素存在时返回它出现的最后一个位置的后面一个位置。
不存在，则返回一个下标k，在此处插入元素，原来的元素全部向后移动一个位置，序列依然有序
*/
int upper_bound(const vector<int> &nums, int target) {
    int left = 0, right = nums.size(), mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 前面不可能有，往后搜，[mid+1, right)
            left = mid + 1;
        } else if (nums[mid] == target) {
            // 如果相等，右边可能还存在，继续往右搜 [mid+1, right)
            left = mid + 1;
        } else if (nums[mid] > target) {
            // 右侧不能有，往前搜 [left, mid)
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> nums = {-1, -2, 0, 0, 0, 0, 3, 4};
    cout << lower_bound(nums, 0) << endl;
    cout << upper_bound(nums, 0) - 1 << endl;
}