#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void replaceSpace(char *str, int length) {
        int space = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ')
                space++;
        }
        if (space == 0) {
            return;
        }
        char *p1 = str + length;
        char *p2 = str + length + space * 2;
        while (p1 < p2) {
            if (*p1 == ' ') {
                *p2 = '0', p2--;
                *p2 = '2', p2--;
                *p2 = '%', p2--;
            } else {
                *p2 = *p1, p2--;
            }
            p1--;
        }
    }
};

int main() {
    Solution solution;
    char *str = (char *) malloc(sizeof(char) * 11);
    strcpy(str, "hello world");
    solution.replaceSpace(str, 11);
    cout << str;
    return 0;
}
