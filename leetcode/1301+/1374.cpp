#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string generateTheString(int n) {
        if (n % 2 == 0) return gen(n - 1) + "b";
        return gen(n);
    }

    string gen(int n) {
        string s = "";
        for (int i = 0; i < n; i++) s.append("a");
        return s;
    }
};