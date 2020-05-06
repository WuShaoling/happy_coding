#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        vector<int> status(light.size() + 1, 0);
        status[0] = 2;

        int blue = 0;
        int lightOn = 0;
        for (int i : light) {
            lightOn++;
            status[i] = 1;
            // 前面是蓝色的，自己染成蓝色的
            if (status[i - 1] == 2) {
                blue++;
                status[i] = 2;
            }
            // 从当前位置开始，往后染色
            for (int j = i + 1; j <= light.size(); j++) {
                if (status[j] == 1) {
                    blue++;
                    status[j] = 2;
                } else
                    break;
            }
            // cout << "---------------" << endl;
            // for (int x = 1; x <= light.size(); x++) cout << x << " ";
            // cout << endl;
            // for (int x = 1; x < status.size(); x++) cout << status[x] << " ";
            // cout << endl << blue << " " << lightOn << endl;
            if (blue == lightOn) res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> light = {1, 2, 3, 4, 5, 6};
    cout << s.numTimesAllBlue(light);
}