#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int i = m + n - 1, j = m - 1; j >= 0; i--, j--) {
            A[i] = A[j];
        }

        int idx = 0;
        int i = n;
        int j = 0;
        while (i < m + n && j < n) {
            if (A[i] < B[j]) {
                A[idx++] = A[i++];
            } else {
                A[idx++] = B[j++];
            }
        }
        while (i < m + n) {
            A[idx++] = A[i++];
        }
        while (j < n) {
            A[idx++] = B[j++];
        }
    }
};

// 0 0 0 0 1 2 3
// 1 2 3 4

int main() {}