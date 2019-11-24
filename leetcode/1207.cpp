#include <iostream>
#include <map>
#include <vector>

#define MAX_SIZE 2010
using namespace std;

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[MAX_SIZE] = {0};
        for (int i = 0; i < arr.size(); i++) {
            count[arr[i] + 1000]++;
        }

        int count2[MAX_SIZE] = {0};
        for (int i = 0; i < MAX_SIZE; i++) {
            if (count[i] != 0) {
                if (count2[count[i]] != 0) {
                    return false;
                }
                count2[count[i]]++;
            }
        }
        return true;
    }
};

int main() {}