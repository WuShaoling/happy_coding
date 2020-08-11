#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K, N, t;
    cin >> K >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> t;
        v.push_back(t);
    }

    if (K == 0) {
        cout << "paradox" << endl;
        return 0;
    }

    int back = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        cur += v[i];
        if (cur == K) {
            cout << "paradox" << endl;
            return 0;
        } else if (cur > K) {
            back++;
            cur = K - (cur - K);
        }
    }
    cout << K - cur << " " << back << endl;
    return 0;
}