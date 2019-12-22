#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }

    int hammingWeight1(uint32_t n) {
        int ans = 0;
        while(n){
            ans++;
            n &= n-1;
        }
        return ans;
    }

    int hammingWeight2(uint32_t n) {
        int ans = 0;
        while(n){
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }

    int hammingWeight3(uint32_t n) {
        int ans = 0;
        while(n){
            ans += n % 2;
            n >>= 1;
        }
        return ans;
    }
};

int main(){
}