#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name == "") {
            return true;
        }
        int i = 0, j = 0;
        for (; i < name.length() && j < typed.length(); i++, j++) {
            if (name[i] != typed[j]) {
                if (i == 0) {
                    return false;
                }
                while (typed[j] == typed[j - 1] && j < typed.length()) j++;
                if (typed[j] != name[i]) {
                    return false;
                }
            }
        }
        if (i < name.length()) {
            return false;
        }
        return true;
    }
};


int main() {
    Solution solution;
    cout << solution.isLongPressedName("pyplrz", "ppyypllr");
}
