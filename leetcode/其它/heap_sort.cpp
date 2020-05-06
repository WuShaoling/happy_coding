#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 调整为大根堆，根最大
void buildMaxHeap(vector<int>& nums) {
    // 从最后一个非叶子节点开始往前调整
    for (int i = (nums.size() - 2) / 2; i >= 0; i--) {
        int index = i;
        // 调整堆
        while (true) {
            int leftIndex = index * 2 + 1;
            int rightIndex = index * 2 + 2;

            if (leftIndex >= nums.size()) break;

            int maxIndex = leftIndex;
            if (rightIndex < nums.size() && nums[rightIndex] > nums[leftIndex])
                maxIndex = rightIndex;

            if (nums[index] >= nums[maxIndex]) break;

            swap(nums[maxIndex], nums[index]);
            index = maxIndex;
        }
    }
}

void heapSort(vector<int>& nums) {
    for (int i = nums.size() - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);

        // 调整堆
        int index = 0;
        while (true) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            if (left >= i) break;

            int maxIndex = left;
            if (right < i && nums[right] > nums[left]) maxIndex = right;

            if (nums[index] >= nums[maxIndex]) break;
            swap(nums[maxIndex], nums[index]);
            index = maxIndex;
        }
    }
}

void show(vector<int>& nums) {
    int begin = 0;
    int size = 1;
    while (begin < nums.size()) {
        for (int i = begin; i < begin + size && i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << endl;
        begin += size;
        size *= 2;
    }
}

int main() {
    vector<int> nums = {4, 3, 2, 1, 6, 9, 15, 40};
    buildMaxHeap(nums);
    // show(nums);
    heapSort(nums);
    for (int i : nums) cout << i << " ";
}
