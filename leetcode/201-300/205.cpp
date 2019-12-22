#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        int mm[256] = {-1};
        memset(mm, -1, 256 * sizeof(int));
        int mb[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            int a = s[i];
            int b = t[i];
            if (mm[a] != -1) {  //如果已经映射了
                if (mm[a] != b) return false;
            } else {  //如果没映射，检查b是否已经被映射
                if (mb[b] != 0) return false;
                mm[a] = b;
                mb[b] = 1;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("13", "42");
}