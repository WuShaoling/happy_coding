#include <iostream>
#include <vector>

using namespace std;

vector<int> f;

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) f[x] = y;
}

int main() {
    int N, M;
    cin >> N >> M;
    f.resize(N + 1);

    for (int i = 0; i < N + 1; i++) f[i] = i;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        merge(x, y);
    }

    int n = 0;
    for (int i = 1; i < N + 1; i++) {
        if (i == f[i]) {
            n++;
            if (n > 1) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}