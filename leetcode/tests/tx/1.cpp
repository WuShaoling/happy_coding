#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        long long int x, k;
        cin >> x >> k;

        // 求 x 层数
        int layer = log2(x) + 1;

        if (k <= 0 || k >= layer) {
            cout << -1 << endl;
        } else {
            while (layer) {
                layer--;
                x /= 2;
                if (layer == k) {
                    cout << x << endl;
                    break;
                }
            }
        }
    }
}