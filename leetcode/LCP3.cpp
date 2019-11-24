#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool robot(string command, vector<vector<int> >& obstacles, int x, int y) {
        int R = 0, U = 0;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'U')
                U++;
            else
                R++;
        }

        for (int i = 0; i < obstacles.size(); i++) {
            if (obstacles[i][0] > x || obstacles[i][1] > y) continue;
            if (pass(command, obstacles[i][0], obstacles[i][1], R, U))
                return false;
        }

        return pass(command, x, y, R, U);
    }

    bool pass(string command, int x, int y, int R, int U) {
        int cicle = min((R == 0) ? x : x / R, (U == 0) ? y : y / U);
        x = x - R * cicle;
        y = y - U * cicle;

        int total = x + y;
        while (command.size() < total) command += command;
        
        int u = 0, r = 0;
        for (int i = 0; i < total; i++) {
            if (command[i] == 'U')
                u++;
            else
                r++;
        }
        
        if (r == x && u == y) return true;
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int> > obstacles = {};
    cout << s.robot("URR", obstacles, 3, 2);
}
