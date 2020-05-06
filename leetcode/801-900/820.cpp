#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef struct TrieNode {
    TrieNode* next[26] = {NULL};
    TrieNode() {}
} * Trie;

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie = buildTrie(words);
        dfs(trie, 0);
        return res;
    }

   private:
    void dfs(Trie trie, int depth) {
        if (!trie) return;

        // 遍历子节点
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (trie->next[i] != NULL) {
                count++;
                dfs(trie->next[i], depth + 1);
            }
        }

        // 如果是叶子节点
        if (count == 0) {
            res += depth + 1;
            return;
        }
    }

    Trie buildTrie(vector<string>& words) {
        Trie trie = new TrieNode();
        for (string str : words) {
            Trie p = trie;
            for (int i = str.size() - 1; i >= 0; i--) {
                int idx = str[i] - 'a';
                if (!p->next[idx]) p->next[idx] = new TrieNode();
                p = p->next[idx];
            }
        }
        return trie;
    }

    int res = 0;
};

int main() {
    Solution s;
    vector<string> words = {"atime", "time", "me", "bell"};
    cout << s.minimumLengthEncoding(words);
}