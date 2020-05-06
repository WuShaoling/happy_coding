#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;

        string str = to_string(N);

        // 如果本来就是非递减的，直接返回
        int i = 1;
        while (i < str.size() && str[i] >= str[i - 1]) i++;
        if (i == str.size()) return N;

        // 找到第一个递减的位置
        i = 1;
        while (i < str.size() && str[i] >= str[i - 1]) i++;
        int j = i - 1;

        // 处理前面相同的部分
        while (j > 0 && str[j] == str[j - 1]) j--;
        str[j++]--;

        // 后面的统一设为9
        while (j < str.size()) str[j++] = '9';
        return stoi(str);
    }
};

int main() {
    Solution s;
    cout << s.monotoneIncreasingDigits(667851);
}