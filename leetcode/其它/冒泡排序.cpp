#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void buble_sort(vector<int>& arr) {
    int len = arr.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    vector<int> arr = {5, 1, 2, 3, 3, 4, 5};
    buble_sort(arr);
    for (int i : arr) cout << i << " ";
}