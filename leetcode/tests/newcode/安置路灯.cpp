#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string str;
        cin >> n;
        cin >> str;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '.') {
                res++;
                i += 2;
            }
        }
        cout << res << endl;
    }
    return 0;
}

// ...XX....XX