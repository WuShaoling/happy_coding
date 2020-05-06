#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size();) {
            bitset<32> b(data[i]);

            if (b[7] == 0) {
                i++;
            } else {
                // i
                // 0 1 2 3 4
                // 0xxxxxxx
                // 110xxxxx 10xxxxxx
                // 1110xxxx 10xxxxxx 10xxxxxx
                // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
                // 76543210
                if (b[6] == 0) return false;
                // 求后面有一个数
                int len = 0;
                if (b[5] == 0) {  // 后面有1个
                    len = 1;
                } else if (b[4] == 0) {  // 后面有2个
                    len = 2;
                } else if (b[3] == 0) {  // 后面有3个
                    len = 3;
                } else {
                    return false;
                }
                // cout << len << endl;
                // 如果剩余个数小于应该需要的数
                if (data.size() - i - 1 < len) return false;
                for (int j = i + 1; j <= i + len; j++) {
                    // cout << data[j] << " " << (data[j] & 128) << endl;
                    if ((data[j] & 128) != 128) return false;
                }
                i += len + 1;
            }
            // cout << b << " " << b[4] << b[3] << b[2] << b[1] << endl;
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> data = {255};
    cout << s.validUtf8(data);
}