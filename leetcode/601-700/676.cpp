#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NODE_SIZE 26
typedef struct TrieNode {
    bool leaf = false;
    TrieNode* next[NODE_SIZE] = {NULL};
    TrieNode() {}
} * Tree;

class MagicDictionary {
   public:
    MagicDictionary() { trie = new TrieNode(); }

    void buildDict(vector<string> dict) {
        for (int i = 0; i < dict.size(); i++) {
            Tree p = trie;
            for (int j = 0; j < dict[i].size(); j++) {
                int index = dict[i][j] - 'a';
                if (p->next[index] == NULL) p->next[index] = new TrieNode();
                p = p->next[index];
            }
            p->leaf = true;
        }
    }

    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            if (searchPartten(trie, word, 0, i, word[i])) {
                return true;
            }
        }
        return false;
    }

   private:
    bool searchPartten(Tree root, string word, int index, int replacePos,
                       char replaceValue) {
        if (word.size() == index) return root->leaf;

        Tree p = root;
        if (index == replacePos) {
            for (int i = 0; i < 26; i++) {
                if (i == replaceValue - 'a') continue;
                if (p->next[i] != NULL &&
                    searchPartten(p->next[i], word, index + 1, replacePos,
                                  replaceValue))
                    return true;
            }
            return false;
        } else {
            if (p->next[word[index] - 'a'] == NULL) {
                return false;
            }
            return searchPartten(p->next[word[index] - 'a'], word, index + 1,
                                 replacePos, replaceValue);
        }
    }

    Tree trie;
};

int main() {
    MagicDictionary m;
    vector<string> d = {"hello", "leetcode"};
    m.buildDict(d);
    cout << m.search("hello") << endl;
    cout << m.search("hellp") << endl;
    cout << m.search("hell") << endl;
    cout << m.search("leetcoded") << endl;
}