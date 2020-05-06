#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef struct TrieNode {
    TrieNode* next[26] = {NULL};
    bool leaf = 0;
} * Trie;

class Solution {
   public:
    vector<string> maxRectangle(vector<string>& words) {
        if (words.empty()) return {};

        // 建立单词长度到单词列表的映射
        vector<vector<string>> len_to_wordlist(1010);
        for (string word : words) {
            if (word.size() == 0) continue;  // 排除掉 ""
            len_to_wordlist[word.size()].push_back(word);
            // 更新最大单词长度
            max_word_len = max(max_word_len, (int)word.size());
        }

        // 排除掉所有单词都是 "" 的情况
        if (len_to_wordlist.size() == 0) return {};

        // 建立字典树
        buildTrie(words);

        // 对于每一种长度的单词
        vector<string> matrix;
        for (int i = max_word_len; i > 0; i--) {
            if (len_to_wordlist[i].size() != 0) {
                if (i * max_word_len <= max_area) break;

                matrix.clear();
                backtrack(len_to_wordlist[i], matrix);
            }
        }

        return ans;
    }

   private:
    int max_word_len = 0;  // 最大单词长度
    Trie root = NULL;      // 字典树
    vector<string> ans;    // 结果
    int max_area = 0;      // 当前最大面积

    void backtrack(vector<string>& words, vector<string>& matrix) {
        // 剪枝
        if (words[0].size() * max_word_len <= max_area) return;
        // 列单词长度大于等于最大单词长度，直接返回
        if (matrix.size() >= max_word_len) return;

        for (int i = 0; i < words.size(); i++) {
            matrix.push_back(words[i]);
            vector<bool> status = searchTrie(matrix);
            if (status[0]) {  //可以继续插入单词
                int cur_area = matrix.size() * matrix[0].size();
                if (status[1] && cur_area > max_area) {
                    ans = matrix;
                    max_area = cur_area;
                }
                backtrack(words, matrix);
            }
            matrix.pop_back();
        }
    }

    // 字典树中搜索
    vector<bool> searchTrie(vector<string>& matrix) {
        bool all_leaf = true;
        for (int col = 0; col < matrix[0].size(); col++) {  // 对于每一列
            Trie p = root;
            for (int row = 0; row < matrix.size(); row++) {  // 对于每一行
                int idx = matrix[row][col] - 'a';
                if (!p->next[idx]) return {false, false};  // 不能继续插入了
                p = p->next[idx];
            }
            all_leaf &= p->leaf;
        }
        // 可以继续插入、每个列单词都在字典中
        return {true, all_leaf};
    }

    void buildTrie(vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            Trie p = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!p->next[idx]) p->next[idx] = new TrieNode();
                p = p->next[idx];
            }
            p->leaf = true;
        }
    }
};

int main() {
    Solution s;
    vector<string> words = {"lcauj", "mdlby",   "myulp", "yvkqn",  "usajk",
                            "rpj",   "bojvf",   "ukmkb", "afqbhs", "j",
                            "ebe",   "yacov",   "wsaep", "zdk",    "wziqrdd",
                            "pcjfn", "nlrehaq", "dasrc", "lruvq",  "dvca"};
    vector<string> ans = s.maxRectangle(words);
    for (string str : ans) cout << str << endl;
}