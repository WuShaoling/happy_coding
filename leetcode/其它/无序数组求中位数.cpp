#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int partSort(int arr[], int start, int end) {
    int low = start;
    int high = end;

    // 读取关键字
    int key = arr[end];
    while (low < high) {
        // 左边的值比key大的值
        while (low < high && arr[low] <= key) {
            ++low;
        }

        // 右边找比key小的值
        while (low < high && arr[high] >= key) {
            --high;
        }

        if (low < high) {
            // 找到之后交换左右的值
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }

    int temp = arr[high];
    arr[high] = arr[end];
    arr[end] = temp;

    return low;
}

// 查找无序数组的中位数
int findMedian(int arr[], int len) {
    int low = 0;
    int high = len - 1;

    int mid = (len - 1) / 2;
    int div = partSort(arr, low, high);

    while (div != mid) {
        if (mid < div) {
            // 左半区查找
            div = partSort(arr, low, div - 1);
        } else {
            // 右半区查找
            div = partSort(arr, div + 1, high);
        }
    }

    // 找到中位数
    return arr[mid];
}

int main() {
    int arr[9] = {1, 1, 1, 1};
    int median = findMedian(arr, 9);
    printf("中位数：%d\n", median);
}

// int partSort(vector<int>& arr, int left, int right) {
//     if (left >= right) return left;

//     int flag = arr[left];
//     int i = left, j = right;
//     while (i < j) {
//         while (i < j && arr[j] >= flag) j--;
//         while (i < j && arr[i] <= flag) i++;
//         if (i < j) swap(arr[i], arr[j]);
//     }
//     swap(arr[left], arr[i]);
//     return i;
// }

// int main() {
//     vector<int> arr = {12, 3, 10, 8, 6, 7, 11, 13, 9};
//     int mid = arr.size() / 2;
// }

//               m
// 12                      i   j
// 0   1  2   3  4  5  6   7   8
// 9 , 3, 10, 8, 6, 7, 11, 12, 13

// 0 1 2 3 4
// 1 2 3 4 5