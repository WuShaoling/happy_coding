#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = 0;
        while(x || y){
            d += abs((x&1) - (y&1));
            x >>= 1;
            y >>= 1;
        }
        return d;
    }
};

int main(){
    Solution s;
    cout << s.hammingDistance(1, 4);
}