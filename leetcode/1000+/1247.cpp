#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                continue;
            } else if (s1[i] == 'x') {
                xy++;
            } else {
                yx++;
            }
        }
        if ((xy + yx) & 1) return -1;
        return (xy + 1) / 2 + (yx + 1) / 2;
    }
};

int main() {}