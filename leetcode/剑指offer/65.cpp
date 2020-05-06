#include <iostream>

using namespace std;

class Solution {
   public:
    int add(int a, int b) {
        if (b == 0) return a;
        int n1 = a ^ b;
        int n2 = a & b;
        cout << n1 << " " << n2 << " " << (n2 << 1) << endl;
        return add(n1, n2 << 1);
    }
};

int main() {
    Solution s;
    cout << s.add(-1, 2);
}