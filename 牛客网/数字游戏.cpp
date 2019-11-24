#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int n, _max = -1;
    cin >> n;
    string t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        sort(t.begin(), t.end());
        _max = max(_max, atoi(t.c_str()));
    }
    cout << _max;
}