#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 特殊情况直接排除
        if (s.empty() || words.empty()) return {};

        //存放结果的数组
        vector<int> result;

        // 单词数组中的单词的大小，个数，以及总长度
        int one_word = words[0].size();
        int word_num = words.size();
        int all_len = one_word * word_num;

        //建立单词->单词个数的映射
        unordered_map<string, int> m1;
        for (const auto& w : words) m1[w]++;

        for (int i = 0; i < one_word; ++i) {
            // left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
            int left = i, right = i, count = 0;

            unordered_map<string, int> m2;
            //开始滑动窗口
            while (right + one_word <= s.size()) {
                //从s中提取一个单词拷贝到w
                string w = s.substr(right, one_word);
                right += one_word;  // 窗口右边界右移一个单词的长度

                // 此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及m2
                if (m1.count(w) == 0) {
                    count = 0;
                    left = right;
                    m2.clear();
                } else {  // 该单词匹配成功，添加到m2中
                    m2[w]++;
                    count++;
                    // 一个单词匹配多次，需要缩小窗口，也就是left右移
                    while (m2.at(w) > m1.at(w)) {
                        count--;
                        m2[s.substr(left, one_word)]--;
                        left += one_word;
                    }
                    if (count == word_num) result.push_back(left);
                }
            }
        }
        return result;
    }
};

// class Solution {
//    public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         if (s.size() == 0 || words.size() == 0 || words[0].size() == 0)
//             return {};

//         unordered_map<string, int> word_map;
//         for (string str : words) word_map[str]++;

//         int n = s.size();
//         int wordCount = words.size();
//         int wordLen = words[0].size();
//         int totalChars = wordCount * wordLen;

//         vector<int> ans;
//         for (int i = 0; i <= n - totalChars; i++) {
//             unordered_map<string, int> temp;
//             bool match = true;
//             for (int j = i, k = 0; k < wordCount; j += wordLen, k++) {
//                 string subStr = s.substr(j, wordLen);
//                 if (word_map[subStr] > 0) {
//                     temp[subStr]++;
//                     if (temp[subStr] > word_map[subStr]) {
//                         match = false;
//                         break;
//                     }
//                 } else {
//                     match = false;
//                     break;
//                 }
//             }
//             if (match) ans.push_back(i);
//         }
//         return ans;
//     }
// };

// typedef struct TrieNode {
//     TrieNode* next[26] = {NULL};
//     vector<int> indexs;  // 在原数组中的位置
// } * Trie;

// class Solution {
//    public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         if (s.size() == 0 || words.size() == 0 || words[0].size() == 0)
//             return {};

//         // 首先计算words的字符数
//         int n = s.size();
//         int wordCount = words.size();
//         int wordLen = words[0].size();
//         int totalChars = wordCount * wordLen;

//         Trie root = buildTrie(words);
//         vector<int> ans;
//         for (int i = 0; i <= n - totalChars; i++) {
//             if (find(root, s, i, wordCount, wordLen)) {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }

//    private:
//     bool find(Trie root, string& s, int begin, int words, int wordLen) {
//         vector<bool> visited(words, false);
//         for (int i = 0; i < words; i++) {
//             Trie p = root;
//             // 开始查找路径
//             for (int j = 0; j < wordLen; j++) {
//                 int idx = s[begin++] - 'a';
//                 // 路径断了，直接返回
//                 if (p->next[idx] == NULL) return false;
//                 p = p->next[idx];
//             }
//             // 路径存在，需要找一个没有被使用的单词
//             bool canFind = false;
//             for (int idx : p->indexs) {
//                 // 单词没有被访问过，可以使用
//                 if (!visited[idx]) {
//                     visited[idx] = true;
//                     canFind = true;
//                     break;
//                 }
//             }
//             if (!canFind) return false;
//         }
//         return true;
//     }

//     Trie buildTrie(vector<string>& words) {
//         Trie root = new TrieNode();
//         for (int i = 0; i < words.size(); i++) {
//             Trie p = root;
//             string word = words[i];
//             for (char c : word) {
//                 int idx = c - 'a';
//                 if (!p->next[idx]) p->next[idx] = new TrieNode();
//                 p = p->next[idx];
//             }
//             p->indexs.push_back(i);
//         }
//         return root;
//     }
// };

int main() {
    Solution s;
    vector<string> words = {"a", "a"};
    vector<int> res = s.findSubstring("a", words);
    for (int i : res) cout << i << " ";
    cout << endl;
}
