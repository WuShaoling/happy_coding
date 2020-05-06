#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int threeSumMulti(vector<int>& A, int target) {
        const int mod = 1e9 + 7;
        sort(A.begin(), A.end());
        int n = A.size(), sum = 0, temp = 0;
        long ans = 0;
        //     i
        // 0 1 2 3 4
        // 1 2 3 4 5
        for (int i = 0; i < n - 2; i++) {
            sum = target - A[i];
            for (int j = i + 1, k = n - 1; j < k;) {
                temp = A[j] + A[k];
                if (temp < sum) {
                    j++;
                } else if (temp > sum) {
                    k--;
                } else {
                    if (A[j] != A[k]) {
                        int left = 1;
                        int right = 1;
                        while (j + 1 < k && A[j] == A[j + 1]) {
                            j++;
                            left++;
                        }
                        while (j < k - 1 && A[k] == A[k - 1]) {
                            k--;
                            right++;
                        }
                        ans += left * right;
                        ans %= mod;
                        j++;
                        k--;
                    } else {
                        ans += (k - j + 1) * (k - j) / 2;
                        ans %= mod;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {}