#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Solution {
   public:
    int calculate(string s) {
        int n = s.size();
        for (int i = 0; i < n;) {
            if (isdigit(s[i])) {
                int j = i + 1;
                while (isdigit(s[j])) j++;
                int num = 0;
            }
        }

        return 0;
    }
};

int main() {}