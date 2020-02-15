#include <iostream>
#include <vector>

using namespace std;

void quickSort(int left, int right, vector<int>& arr) {
    if (left >= right) return;

    int i = left;
    int j = right;
    int base = arr[left];
    while (i < j) {
        while (i < j && arr[j] >= base) j--;
        while (i < j && arr[i] <= base) i++;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[i]);

    quickSort(left, i - 1, arr);
    quickSort(i + 1, right, arr);
}

int main() {
    vector<int> arr = {0, -1, 57, 68, 59, 52, 72, 28, 96, 33, 24, 24, 24};
    quickSort(0, arr.size() - 1, arr);
    for (int i : arr) cout << i << " ";
    return 0;
}
