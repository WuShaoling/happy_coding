#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
        public:
        bool Find(int target, vector<vector<int> > array) {
            if (array.size() == 0 || array[0].size() == 0) {
                return false;
            }
            int rows = array.size();
            int cols = array[0].size();
            int r = 0, c = cols - 1;
            while (r < rows && c >= 0) {
                if (array[r][c] == target) {
                    return true;
                } else if (target > array[r][c]) {
                    r++;
                } else {
                    c--;
                }
            }

            return false;
        }
};

//int main() {
//    Solution solution;
//
//    vector<vector<int> > array;
//    vector<int> arr1;
//    arr1.push_back(1);
//    arr1.push_back(6);
//    arr1.push_back(11);
//    arr1.push_back(16);
//    arr1.push_back(21);
//    array.push_back(arr1);
//
//    vector<int> arr2;
//    arr2.push_back(2);
//    arr2.push_back(7);
//    arr2.push_back(12);
//    arr2.push_back(17);
//    arr2.push_back(22);
//    array.push_back(arr2);
//
//    vector<int> arr3;
//    arr3.push_back(3);
//    arr3.push_back(8);
//    arr3.push_back(13);
//    arr3.push_back(18);
//    arr3.push_back(23);
//    array.push_back(arr3);
//
//    vector<int> arr4;
//    arr4.push_back(4);
//    arr4.push_back(9);
//    arr4.push_back(14);
//    arr4.push_back(19);
//    arr4.push_back(24);
//    array.push_back(arr4);
//
//    vector<int> arr5;
//    arr5.push_back(5);
//    arr5.push_back(10);
//    arr5.push_back(15);
//    arr5.push_back(20);
//    arr5.push_back(25);
//    array.push_back(arr5);
//
//    cout << solution.Find(5, array) << endl;
//
//    return 0;
//}
