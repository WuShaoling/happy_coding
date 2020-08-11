#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string words) {
    if (words.size() == 0) return true;

    char str[words.size()];
    int len = 0;
    for (char c : words) {
        if (c >= '0' && c <= '9') {
            str[len++] = c;
        } else if (c >= 'a' && c <= 'z') {
            str[len++] = c;
        } else if (c >= 'A' && c <= 'Z') {
            str[len++] = tolower(c);
        }
    }
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str = "A man, a plan, a canal: Panama";
    cout << isPalindrome(str);
}