#include <iostream>
#include <vector>

using namespace std;

/*
i   m     j
0 1 2 3 4 5
1 2 3 3 5 6

3
*/

void find_right() {
    int left = 0, right = 6;
    int target = 3;
    vector<int> nums = {1, 2, 3, 3, 5, 6};
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << " " << nums[left] << endl;
}

void find_left() {
    int left = 0, right = 6;
    int target = 100;
    vector<int> nums = {1, 2, 3, 3, 5, 6};
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << " " << nums[left] << endl;
}

int main() {
    find_right();
}