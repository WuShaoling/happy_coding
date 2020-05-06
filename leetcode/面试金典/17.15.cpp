#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const string& str1, const string& str2) {
                 if (str1.size() == str2.size()) return str1 < str2;
                 return str1.size() > str2.size();
             });

        set<string> dic(words.begin(), words.end());
        unordered_map<string, bool> mm;

        for (string str : words) {
            if (find(dic, str, 0, 0, mm)) return str;
        }

        return "";
    }

    bool find(set<string>& dic, string& word, int index, int count,
              unordered_map<string, bool>& mm) {
        if (index == word.size()) return count > 1;

        for (int i = index + 1; i <= word.size(); i++) {
            if (dic.find(word.substr(index, i - index)) != dic.end()) {
                string left = word.substr(i, word.size() - i);
                if (mm[left] == true) return true;
                
                bool res = find(dic, word, i, count + 1, mm);
                mm[left] = res;
                if (res) return true;
            }
        }
        return false;
    }
};

// class Solution {
//    public:
//     string longestWord(vector<string>& words) {
//         sort(words.begin(), words.end(),
//              [](const string& str1, const string& str2) {
//                  if (str1.size() == str2.size()) return str1 < str2;
//                  return str1.size() > str2.size();
//              });

//         set<string> dic(words.begin(), words.end());

//         for (string str : words) {
//             if (find(dic, str, 0, 0)) return str;
//         }

//         return "";
//     }

//     bool find(set<string>& dic, string& word, int index, int count) {
//         if (index == word.size()) return count > 1;

//         for (int i = index + 1; i <= word.size(); i++) {
//             if (dic.find(word.substr(index, i - index)) != dic.end() &&
//                 find(dic, word, i, count + 1)) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

int main() {
    Solution s;
    vector<string> words = {"mbzznzbccc", "zbmcbbcbze", "cbz", "cbzcbz"};
    // {"cat",  "banana", "dog",      "nana",  "walk", "walker", "dogwalker"};
    cout << s.longestWord(words);
}