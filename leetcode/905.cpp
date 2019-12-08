#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        for (int i = 0, j = A.size() - 1; i < j; i++, j--) {
            while (i < j && A[i] % 2 == 0) i++;
            while (i < j && A[j] % 2 != 0) j--;
            swap(A[i], A[j]);
        }
        return A;
    }
};

int main() {
    Solution solution;
    vector<int> A;
    A.push_back(3);
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    vector<int> res = solution.sortArrayByParity(A);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
