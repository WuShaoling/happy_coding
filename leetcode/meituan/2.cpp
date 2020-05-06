#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + k; j < n; j++) {
            for (int l = j + 1; j < n; j++) {
                if (l + (j - i) > n) break;
                if (s.substr(i, j - i + 1) == s.substr(l, j - i + 1)) {
                    res += 1;
                }
            }
        }
    }
    cout << res << endl;
}

//  ij
// abcd