#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp(high - low + 1);
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high) {
        if (nums[i] < nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= high) temp[k++] = nums[j++];
    for (int a = 0; a < high - low + 1; a++) {
        nums[a + low] = temp[a];
    }
}

vector<int> sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        sort(arr, low, mid);
        sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    return arr;
}

int main() {
    vector<int> arr = {1, 3, 2, 3, 1};
    vector<int> res = sort(arr, 0, arr.size() - 1);
    for (int i : res) cout << i << " ";
}