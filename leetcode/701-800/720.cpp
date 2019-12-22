#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct TrieNode {
    string value;
    bool leaf;
    TrieNode* next[26] = {NULL};
    TrieNode() {
        value = "";
        leaf = false;
    }
} * Trie;

class Solution {
   public:
    string longestWord(vector<string>& words) {
        buildTrie(words);
        res = "";
        find(root, false);
        return res;
    }

   private:
    void find(Trie trie, bool begin) {
        if (trie == NULL || !trie->leaf) {
            return;
        }

        // 首次不进行比较操作
        if (begin == false) {
            begin = true;
        } else {
            if (trie->value.size() > res.size() ||
                (trie->value.size() == res.size() && trie->value < res)) {
                res = trie->value;
            }
        }

        for (int i = 25; i >= 0; i--) {
            find(trie->next[i], begin);
        }
    }

    void buildTrie(vector<string>& words) {
        root = new TrieNode();
        root->leaf = true;
        for (int i = 0; i < words.size(); i++) {
            Trie p = root;
            for (int j = 0; j < words[i].size(); j++) {
                int index = words[i][j] - 'a';
                if (p->next[index] == NULL) p->next[index] = new TrieNode();
                p = p->next[index];
            }
            p->value = words[i];
            p->leaf = true;
        }
    }

    Trie root;
    string res;
};

int main() {
    Solution s;
    vector<string> words = {"a",  "banana", "app",  "appl",
                            "ap", "apply",  "apple"};
    cout << s.longestWord(words);
}