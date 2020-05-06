#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> res;

        for (int i = 0, j = array.size() - 1; i < j;) {
            if (array[i] + array[j] == sum) {
                if (res.size() == 0) {
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                } else {
                    if (res[0] * res[1] > array[i] * array[j]) {
                        res[0] = array[i];
                        res[1] = array[j];
                    }
                }
                i++, j--;
            } else if (array[i] + array[j] > sum) {
                j--;
            } else {
                i++;
            }
        }

        return res;
    }
};

int main() {}