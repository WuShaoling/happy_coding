#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long int ULL;

class Solution {
   public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        ULL base = 0;
        for (char c : longUrl) {
            base += c;
            base %= LONG_MAX;
        }

        srand((unsigned)time(NULL));
        while (true) {
            ULL index = base + rand();
            if (mm.find(index) == mm.end()) {
                mm[index] = longUrl;
                return "http://tinyurl.com/" + to_string(index);
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int pos = shortUrl.find_last_of("/");
        string subStr = shortUrl.substr(pos + 1, shortUrl.size() - pos);
        const char* arr = subStr.c_str();
        char* end;
        ULL index = strtoull(arr, &end, 10);

        return mm[index];
    }

   private:
    ULL MAX_ULL = ~0LL >> 1;
    unordered_map<ULL, string> mm;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    Solution s;
    string shortUrl = s.encode("http://baidu.com");
    cout << shortUrl << endl;
    string longUrl = s.decode(shortUrl);
    cout << longUrl << endl;
}