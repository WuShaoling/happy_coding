#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int longestPalindrome(string s) {
        int mm[52] = {0};
        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                mm[c - 'a']++;
            else
                mm[c - 'A' + 26]++;
        }

        int left = 0;
        int res = 0;
        for (int i = 0; i < 52; i++) {
            if (mm[i] % 2 == 0) {
                res += mm[i];
            } else {
                res += mm[i] - 1;
                left = 1;
            }
        }
        return res + left;
    }
};

int main() {
    Solution s;
    string str =
        "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicated"
        "canlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicp"
        "ateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlive"
        "sthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisB"
        "utinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgr"
        "oundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfarabove"
        "ourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongremember"
        "whatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathe"
        "rtobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfa"
        "rsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremain"
        "ingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcausef"
        "orwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvetha"
        "tthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbi"
        "rthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallno"
        "tperishfromtheearth";
    cout << s.longestPalindrome(str);
}