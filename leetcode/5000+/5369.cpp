#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numTeams(vector<int>& rating) {
        if (rating.size() < 3) return 0;

        int res = 0;
        int leftSmall = 0;
        int leftBigger = 0;
        int rightSmall = 0;
        int rightBigger = 0;
        for (int i = 0; i < rating.size(); i++) {
            leftSmall = leftBigger = rightSmall = rightBigger = 0;

            for (int j = i - 1; j >= 0; j--) {
                if (rating[j] < rating[i]) leftSmall++;
                if (rating[j] > rating[i]) leftBigger++;
            }

            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] < rating[i]) rightSmall++;
                if (rating[j] > rating[i]) rightBigger++;
            }

            res += leftSmall * rightBigger + leftBigger * rightSmall;
        }

        return res;
    }
};

int main() {}