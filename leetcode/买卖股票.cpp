#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n;
    while (cin >> n) {
        arr.push_back(n);
    }

    for (int i : arr) {
        cout << i << " ";
    }
}