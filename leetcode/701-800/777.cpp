#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool canTransform(string start, string end) {
        int m = start.size();
        int n = end.size();

        int i = 0, j = 0;
        while (i < m && j < n) {
            while (i < m && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;
            if (i == m && j == n)
                return true;
            else if (i == m || j == n)
                return false;
            if (start[i] != end[j]) return false;

            if (start[i] == 'L') {  // L可以向左移动
                if (i < j) return false;
            } else if (start[i] == 'R') {  // R可以向右移动
                if (i > j) return false;
            }

            i++;
            j++;
        }
        while (i != m) {
            if (start[i] != 'X') return false;
            i++;
        }
        while (j != n) {
            if (end[j] != 'X') return false;
            j++;
        }
        return true;
    }
};

/*

RXXLRXRXL
XRLXXRRLX

*/

int main() {
    Solution s;
    cout << s.canTransform("XXXXXLXXXLXXXX", "XXLXXXXXXXXLXX");
}