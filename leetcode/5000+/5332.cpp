#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        map<int, bool> mm;
        for (int i : arr) {
            if (mm.find(i * 2) != mm.end()) return true;
            if (i % 2 == 0 && mm.find(i / 2) != mm.end()) return true;
            mm[i] = true;
        }
        return false;
    }
};

int main() {}