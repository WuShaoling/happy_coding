#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int GetMinDistance(string S1, string S2) {
        map<pair<char, char>, int> diff;
        int same[26] = {0};
        int sameSum = 0;
        for (int i = 0; i < S1.size(); i++) {
            if (S1[i] != S2[i]) {
                diff[{S1[i], S2[i]}]++;
            } else {
                same[S2[i] - 'a']++;
                sameSum++;
            }
        }

        int maxSame = sameSum;
        for (int i = 0; i < S1.size(); i++) {
            if (S1[i] != S2[i]) {
                int t = diff[{S1[i], S2[i]}] - same[S1[i] - 'a'];
                if (t > 0) {
                    maxSame = max(maxSame, sameSum + t);
                }
            }
        }

        return S1.size() - maxSame;
    }
};

int main() {
    Solution s;
    cout << s.GetMinDistance(
        "dlqaeopeekqbovglocneojijqyyusjvqcvwtmvqtlvyolfbekp",
        "ruwhgprgrpvvdnprhtyvprligsgiyeysvdfmcywkragwxmakhd");
}
