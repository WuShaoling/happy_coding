#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string line;
    map<string, int> mm;
    for (int i = 0; i < n; i++) {
        cin >> line;
        mm[line]++;
    }

    vector<pair<string, int>> strs;
    for (auto it : mm) strs.push_back(it);

    sort(strs.begin(), strs.end(),
         [](const pair<string, int>& str1, const pair<string, int>& str2) {
             return str1.first < str2.first;
         });

    for (pair<string, int> p : strs) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}