#include <iostream>
#include <vector>

using namespace std;

unsigned long gcd(unsigned long a, unsigned long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int n;
    cin >> n;
    vector<unsigned long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<unsigned long> diff(n - 1);
    for (int i = 1; i < n; i++) {
        unsigned long d = nums[i] - nums[i - 1];
        if (d <= 0) {
            cout << -1 << endl;
            return 0;
        }
        diff[i - 1] = d;
    }

    if (diff.size() == 1) {
        cout << diff[0] << endl;
        return 0;
    }
    unsigned long g = gcd(diff[0], diff[1]);
    // cout << diff[0] << diff[1] << g << endl;
    // 2 4 8
    for (int i = 2; i < diff.size(); i++) {
        g = gcd(g, diff[i]);
        // cout << g << endl;
    }
    cout << g << endl;
    return 0;
}