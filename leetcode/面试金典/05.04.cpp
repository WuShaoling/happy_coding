#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findClosedNumbers(int num) {
        // bitset<32> n(num);
        // cout << n << endl;

        bitset<32> small(num);
        bitset<32> bigger(num);

        int s = -1;
        // small, 10 转 01，1移到左侧
        for (int i = 1; i < 32; i++) {
            if (small[i] == 1 && small[i - 1] == 0) {
                small.flip(i);
                small.flip(i - 1);
                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && small[left] == 0) left++;
                    while (left < right && small[right] == 1) right--;
                    small.flip(left);
                    small.flip(right);
                }
                // cout << small << endl;
                s = (int)small.to_ulong();
                break;
            }
        }

        // bigger, 01转10，1移到最右侧
        int b = -1;
        for (int i = 1; i < 32; i++) {
            if (bigger[i] == 0 && bigger[i - 1] == 1) {
                bigger.flip(i);
                bigger.flip(i - 1);

                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && bigger[left] == 1) left++;
                    while (left < right && bigger[right] == 0) right--;
                    bigger.flip(left);
                    bigger.flip(right);
                }
                // cout << bigger << endl;
                b = (int)bigger.to_ulong();
                break;
            }
        }

        return {b, s};
    }

    // vector<int> findClosedNumbers(int num) {
    //     int small = find_small(num);
    //     int bigger = find_bigger(num);
    //     return {bigger, small};
    // }

    // // 找到01，转成10，把左侧的1都移到右边
    // int find_bigger(int num) {
    //     int count1 = 0;
    //     int right = 0b01;
    //     int cur = 0b10;
    //     for (int i = 1; i < 32; i++) {
    //         if ((num & cur) == 0) {  // 当前位是0
    //             if ((num & right) == right) {
    //                 // 反转第i位的0为1
    //                 num |= (1 << i);

    //                 // 反转第i-1位的1位0
    //                 num &= (~(1 << (i - 1)));

    //                 if (count1 != 0) {
    //                     // 清零
    //                     num &= (((unsigned int)(INT_MAX) << (i - 1)) &
    //                     INT_MAX);
    //                     // 补1
    //                     num |=
    //                         ((~((unsigned int)(INT_MAX) << count1)) &
    //                         INT_MAX);
    //                 }
    //                 return num;
    //             }
    //         }
    //         if ((num & right) == right) count1++;
    //         cur <<= 1;
    //         right <<= 1;
    //     }
    //     return -1;
    // }

    // // 找到10，转成01，把左侧的1都移到左边
    // int find_small(int num) {
    //     int count1 = num & 1;
    //     int right = 0b01;
    //     int cur = 0b10;
    //     for (int i = 1; i < 31; i++) {
    //         if ((num & cur) == cur) {
    //             if ((num & right) == 0) {
    //                 // 反转第i位的1为0
    //                 num &= (~(1 << i));
    //                 // 反转第i-1位的0位1
    //                 num |= (1 << (i - 1));
    //                 // count1 个 1 移到 i-1 以后位置
    //                 for (int j = i - 2, k = count1; k > 0; j--, k--) {
    //                     num |= (1 << j);
    //                 }
    //                 // 剩下的清零
    //                 unsigned int t = INT_MAX;
    //                 num &= ((t << (i - 1 - count1)) & INT_MAX);
    //                 return num;
    //             }
    //             count1++;
    //         }
    //         cur <<= 1;
    //         right <<= 1;
    //     }
    //     return -1;
    // }
};

int main() {
    Solution s;
    vector<int> res = s.findClosedNumbers(1837591841);
    cout << 1837591841 << ": " << bitset<32>(1837591841) << endl;
    cout << res[0] << ": " << bitset<32>(res[0]) << endl;
    cout << res[1] << ": " << bitset<32>(res[1]) << endl;
}
