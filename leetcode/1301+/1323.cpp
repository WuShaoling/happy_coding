#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximum69Number(int num) {
        char str[15];
        sprintf(str, "%d", num);
        int res = 1;
        for (int i = 0; str[i]; i++) {
            if (str[i] == '6') {
                str[i] = '9';
                break;
            }
        }
        return atoi(str);
    }
};

int main() {
    Solution s;
    cout << s.maximum69Number(6);
}