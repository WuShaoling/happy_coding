#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        // quickSort(nums, 0, nums.size() - 1);
        // mergeSort(nums, 0, nums.size() - 1);
        // bucketSort(nums);
        // radixSort(nums);
        // heapSort(nums);
        bubbleSort(nums);
        return nums;
    }

   private:
    // 归并排序
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];

        i = left;
        for (int v : temp) nums[i++] = v;
    }

    // 桶排序
    void bucketSort(vector<int>& nums) {
        // 桶的个数
        int bucketCount = 10;

        // 求每桶内元素的个数
        int _min = INT_MAX;
        int _max = INT_MIN;
        for (int i : nums) {
            _min = min(_min, i);
            _max = max(_max, i);
        }
        int countPerBucket = ceil(double(_max - _min + 1) / bucketCount);

        // 分桶
        vector<vector<int>> bucket(bucketCount + 1);
        for (int num : nums)
            bucket[(num - _min) / countPerBucket].push_back(num);

        // 每个桶排序
        for (int i = 0; i < bucketCount; i++)
            quickSort(bucket[i], 0, bucket[i].size() - 1);

        // 合并结果
        int idx = 0;
        for (int i = 0; i < bucketCount; i++) {
            for (int j : bucket[i]) {
                nums[idx++] = j;
            }
        }
    }

    // 快速排序
    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int flag = nums[left];
            int i = left, j = right;
            while (i < j) {
                while (i < j && nums[j] >= flag) j--;
                while (i < j && nums[i] <= flag) i++;
                if (i < j) {
                    swap(nums[i], nums[j]);
                }
            }
            swap(nums[left], nums[i]);
            quickSort(nums, left, i - 1);
            quickSort(nums, i + 1, right);
        }
    }

    // 基数排序
    void radixSort(vector<int>& nums) {
        const int base = 50000;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] += base;
            maxLen = max(maxLen, getNumLen(nums[i]));
        }

        for (int i = 0; i < maxLen; i++) {
            // 分桶
            vector<vector<int>> radix(10);
            for (int num : nums) {
                int t = num;
                for (int j = 0; j < i; j++) t /= 10;
                radix[t % 10].push_back(num);
            }
            // 合并
            int idx = 0;
            for (vector<int> bucket : radix) {
                for (int x : bucket) {
                    nums[idx++] = x;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= base;
        }
    }

    int getNumLen(int num) {
        int res = 0;
        do {
            res++;
            num /= 10;
        } while (num);
        return res;
    }

    // 堆排序
    void heapSort(vector<int>& nums) {
        // 调整成大根堆
        for (int i = (nums.size() - 2) / 2; i >= 0; i--) {
            int p = i;
            while (true) {
                int left = p * 2 + 1;
                if (left >= nums.size()) break;

                // 获取左右子树中值较大的那个下标
                int maxIndex = left;
                int right = p * 2 + 2;
                if (right < nums.size() && nums[right] > nums[left])
                    maxIndex = right;

                if (nums[p] >= nums[maxIndex]) break;
                swap(nums[p], nums[maxIndex]);
                p = maxIndex;
            }
        }

        for (int i = nums.size() - 1; i > 0; i--) {
            swap(nums[i], nums[0]);
            int p = 0;
            while (true) {
                int left = p * 2 + 1;
                if (left >= i) break;

                int maxIndex = left;
                int right = left + 1;
                if (right < i && nums[right] > nums[left]) maxIndex = right;

                if (nums[p] >= nums[maxIndex]) break;
                swap(nums[p], nums[maxIndex]);
                p = maxIndex;
            }
        }
    }

    void bubbleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j - 1]) swap(nums[j], nums[j - 1]);
            }
        }
    }

};

int main() {
    Solution s;
    vector<int> nums = {202, 300, 95, 2, 1, 224, 3, 2, 1, 3, 45, 5, 1010};
    // vector<int> nums = {1, -1};
    s.sortArray(nums);
    for (int i : nums) cout << i << " ";
    cout << endl;
}
