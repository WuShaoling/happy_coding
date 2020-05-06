#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

void quickSort1(int begin, int end, vector<int>& arr) {
    if (begin >= end) return;

    stack<pair<int, int>> s;
    s.push({begin, end});

    int left, right, i, j;
    while (!s.empty()) {
        left = s.top().first;
        right = s.top().second;
        s.pop();
        if (left >= right) continue;

        i = left;
        j = right;
        int base = arr[left];
        while (i < j) {
            while (i < j && arr[j] >= base) j--;
            while (i < j && arr[i] <= base) i++;
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[left]);
        s.push({left, i - 1});
        s.push({i + 1, right});
    }
}

int main() {
    // vector<int> arr = {};
    vector<int> arr = {0, -1, 57, 68, 59, 52, 72, 28, 96, 33, 24, 24, 24};
    quickSort1(0, arr.size() - 1, arr);
    for (int i : arr) cout << i << " ";
    return 0;
}
