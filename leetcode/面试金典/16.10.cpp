#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> lives(101, 0);
        vector<int> changes(102, 0);

        for (int i = 0; i < birth.size(); i++) {
            changes[birth[i] - 1900]++;
            changes[death[i] - 1899]--;
        }

        lives[0] = changes[0];
        int maxlives = lives[0];
        int resy = 1900;
        for (int i = 1; i < 101; ++i) {
            lives[i] = lives[i - 1] + changes[i];
            if (lives[i] > maxlives) {
                maxlives = lives[i];
                resy = i + 1900;
            }
        }
        return resy;
    }
};

int main() {}