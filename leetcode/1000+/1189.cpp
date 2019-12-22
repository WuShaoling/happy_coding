#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        int arr[26] = {0};
        for (int i = 0; i < text.size(); i++) {
            arr[text[i] - 'a']++;
        }

        int _min = 10e5;

        // a, b, l, n, o
        int index[] = {0, 1, 11, 13, 14};
        arr[11] /= 2;
        arr[14] /= 2;

        for (int i = 0; i < 5; i++) {
            // cout << index[i] << " " << arr[index[i]] << endl;
            if (arr[index[i]] < _min) {
                _min = arr[index[i]];
            }
        }
        return _min;
    }
};

int main() {
    Solution s;
    cout << s.maxNumberOfBalloons("balloon");
}