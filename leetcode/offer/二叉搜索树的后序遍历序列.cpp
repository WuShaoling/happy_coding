#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) return false;
        return helper(sequence, 0, sequence.size() - 1);
    }

   private:
    bool helper(vector<int> sequence, int begin, int end) {
        if (begin >= end) return true;

        int root = sequence[end];

        int i = begin;
        for (; i < end; i++) {
            if (sequence[i] > root) {
                break;
            }
        }

        for (int j = i; j < end; j++) {
            if (sequence[j] < root) {
                return false;
            }
        }

        return helper(sequence, begin, i - 1) && helper(sequence, i, end - 1);
    }
};

int main() {}