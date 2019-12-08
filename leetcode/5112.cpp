#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string StrToHex(std::string str) {
    unsigned char c;
    char buf[2];
    std::string result = "";
    std::stringstream ss;
    ss << str;
    while (ss.read((char *)(&c), sizeof(c))) {
        sprintf(buf, "%02x", c);
        result += buf;
    }
    return result;
}

int DectoHex(int dec, unsigned char *hex, int length) {
    int i;
    for (i = length - 1; i >= 0; i--) {
        hex[i] = (dec % 256) & 0xFF;
        dec /= 256;
    }
    return 0;
}

class Solution {
   public:
    string toHexspeak(string num) {
        long n = stol(num);

        string res = StrToHex(num);
        cout << res << endl;
        string a = "";
        for (char c : res) {
            if (c == '0')
                a += 'O';
            else if (c == '1')
                a += 'I';
            else if (c >= 'A' && c <= 'F') {
                a += c;
            } else {
                return "ERROR";
            }
        }
        return a;
    }
};

int main() {
    Solution s;
    s.toHexspeak("257");
}
