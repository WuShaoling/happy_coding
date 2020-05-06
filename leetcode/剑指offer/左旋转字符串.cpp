#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string LeftRotateString(string str, int n) {
        if (str.size() == 0 || n <= 0) return str;

        n %= str.size();
        if (n == 0) return str;

        my_reverse(str, 0, n - 1);
        my_reverse(str, n, str.size() - 1);
        my_reverse(str, 0, str.size() - 1);

        return str;
    }

   private:
    void my_reverse(string& str, int begin, int end) {
        while (begin < end) {
            swap(str[begin], str[end]);
            begin++;
            end--;
        }
    }
};

int main() {
    Solution s;
    cout << s.LeftRotateString("abcdef", 2);
}