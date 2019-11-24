#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int f(string s, int j, int k) {
    for (; j >= 0, k < s.length(); j--, k++) {
        if (s[j] != s[k]) {
            return -10;
        }
    }
    return j;
}

int main() {
    string s = "";
    cin >> s;
    int mid = s.length() / 2;
    for (int i = mid; i < s.length(); i++) {
        int n1 = f(s, i - 1, i);
        int n2 = f(s, i, i);
        if (n1 != -10 && n2 != -10) {
            cout << s.length() + (n1 < n2 ? n1 : n2) + 1 << endl;
            return 0;
        } else if (n1 != -10 && n2 == -10) {
            cout << s.length() + n1 + 1 << endl;
            return 0;
        } else if (n1 == -10 && n2 != -10) {
            cout << s.length() + n2 + 1 << endl;
            return 0;
        }
    }
    return 0;
}