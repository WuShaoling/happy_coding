#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long n, m, a, b;

    while (N--) {
        cin >> n >> m >> a >> b;
        long res = 0;
        for (int i = 0; i < n; i += a) {
            res += b;
        }
        cout << (min(res, m)) << endl;
    }

    // n秒
    // m个
    // a血量
    // b范围
}