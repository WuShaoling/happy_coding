#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int len = array.size();
        vector<int> mm(2 * len + 1, -2);
        mm[len] = -1;

        int res = 0, count = 0, begin = 0, end = 0;
        for (int i = 0; i < array.size(); i++) {
            bool is_num = true;
            if (array[i][0] < '0' || array[i][0] > '9') {
                is_num = false;
            }
            count += is_num ? -1 : 1;

            if (mm[count + len] > -2) {
                if (i - mm[count + len] > res) {
                    begin = mm[count + len] + 1;
                    end = i + 1;
                    res = i - mm[count + len];
                }
            } else {
                mm[count + len] = i;
            }
        }

        vector<string> arr;
        for (int i = begin; i < end; i++) {
            arr.push_back(array[i]);
        }
        return arr;

        // map<int, int> mm;
        // mm[0] = 0;
        // int sum = 0, right = 0, length = 0;
        // for (int i = 0; i < array.size(); i++) {
        //     if (array[i][0] >= 'A' && array[i][0] <= 'Z') {
        //         sum--;
        //     } else {
        //         sum++;
        //     }

        //     if (mm.find(sum) == mm.end()) {
        //         mm[sum] = i;
        //     } else {
        //         if (sum == 0) {
        //             right = i + 1;
        //             length = i + 1;
        //         } else if (i - mm[sum] > length) {
        //             length = i - mm[sum];
        //             right = i + 1;
        //         }
        //     }
        // }

        // vector<string> res;
        // for (int i = right - length; i < right; i++) {
        //     res.push_back(array[i]);
        // }
        // return res;
    }
};

int main() {
    Solution s;
    vector<string> input = {"1", "A"};
    vector<string> res = s.findLongestSubarray(input);
    for (string str : res) cout << str << " ";
}