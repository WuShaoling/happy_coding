#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), [](const int& a, const int& b) {
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });
        string res;
        for (auto c : numbers) {
            cout << c << endl;
            res += to_string(c);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> numbers = {3, 32, 321};
    cout << s.PrintMinNumber(numbers);
}