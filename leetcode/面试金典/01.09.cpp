#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        if ((s2 + s2).find(s1) == string::npos) return false;

        return true;
    }
};

int main() {}