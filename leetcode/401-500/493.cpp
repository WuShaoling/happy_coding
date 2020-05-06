#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        merge_sort(count, nums);
        return count;
    }

    void merge_sort(int& count, vector<int>& v) {
        if (v.size() <= 1) return;
        vector<int> temp(v.size());
        merge_sort(count, v, temp, 0, v.size() - 1);
    }

    void merge_sort(int& count, vector<int>& v, vector<int>& temp, int left,
                    int right) {
        if (left == right) return;

        int mid = left + ((right - left) >> 1);

        merge_sort(count, v, temp, left, mid);
        merge_sort(count, v, temp, mid + 1, right);

        merge(count, v, temp, left, mid, right);
    }

    // 2、升序排列 从左到右合并
    void merge(int& count, vector<int>& v, vector<int>& temp, int left, int mid,
               int right) {
        // 在merge前统计count  而不在merge过程中统计
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            // 则左边i到mid都符合 统计个数 并看下一个j
            if (v.at(i) > 2LL * v.at(j)) {
                count += mid - i + 1;
                ++j;
            } else {  // 则j到right都不符合 看下一个i
                ++i;
            }
        }

        i = left;
        j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (v.at(i) <= v.at(j)) {  // 升序
                temp[k++] = v.at(i++);
            } else {
                temp[k++] = v.at(j++);
            }
        }

        while (i <= mid) temp[k++] = v.at(i++);
        while (j <= right) temp[k++] = v.at(j++);

        for (int i = left; i <= right; ++i) {
            v.at(i) = temp.at(i);
        }
    }
};

int main() {}