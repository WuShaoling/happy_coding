#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string node;

        int slot = 1;
        while (getline(ss, node, ',')) {
            slot--;
            if (slot < 0) return false;
            if (node != "#") slot += 2;
        }

        return slot == 0;
    }
};

int main() {}