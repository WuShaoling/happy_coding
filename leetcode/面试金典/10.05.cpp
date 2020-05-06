#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    int findString(vector<string>& words, string s) {
        return find(words, s, 0, words.size() - 1);
    }

   private:
    int find(vector<string>& words, string s, int left, int right) {
        // 去除首尾是空字符
        while (left < right && words[left] == "") left++;
        while (left < right && words[right] == "") right--;
        if (left > right || (left == right && words[left] == "")) return -1;

        int mid = left + (right - left) / 2;
        int i = mid;

        // cout << left << " " << mid << " " << right << endl;

        // 先查找左边
        while (left < i && words[i] == "") i--;
        if (words[i] == s)
            return i;
        else if (words[i] > s)
            return find(words, s, left, i - 1);

        // 可能出现在右边
        i = mid;
        while (i < right && words[i] == "") i++;
        if (words[i] == s)
            return i;
        else if (words[i] < s)
            return find(words, s, i + 1, right);

        return -1;
    }
};

int main() {
    Solution s;
    vector<string> words = {"at",  "", "", "",    "ball", "", "",
                            "car", "", "", "dad", "",     ""};
    cout << s.findString(words, "ball") << endl;
}

// g++ -std=c++11 10.03.cpp -o 10.03 ; ./10.03