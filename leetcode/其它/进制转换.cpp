#include <iostream>
#include <vector>

using namespace std;

void show(vector<char>& v) {
    reverse(v.begin(), v.end());
    for (int i : v) cout << (char)i;
    cout << endl;
}

void int10To2(int n) {
    const int base = 2;
    char arr[16] = {'0', '1'};

    vector<char> v;
    while (n) {
        v.push_back(arr[n % base]);
        n /= base;
    }

    show(v);
}

void int10To16(int n) {
    const int base = 16;
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    vector<char> v;
    while (n) {
        v.push_back(arr[n % base]);
        n /= base;
    }

    show(v);
}

int main() {
    int n = 100;
    int10To2(n);
    int10To16(n);
}