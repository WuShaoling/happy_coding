#include <iostream>
#include <string>

using namespace std;

#define NODE_SIZE 26

typedef struct TrieNode {
    bool leaf = false;
    TrieNode* next[NODE_SIZE] = {NULL};
    TrieNode() {}
} * Tree;

class WordDictionary {
   public:
    /** Initialize your data structure here. */
    WordDictionary() { trie = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Tree p = trie;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] == NULL) p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->leaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) { return searchPartten(trie, word, 0); }

    bool searchPartten(Tree root, string word, int index) {
        Tree p = root;

        if (word.size() == index) {
            return p->leaf;
        }

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (p->next[i] != NULL &&
                    searchPartten(p->next[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (p->next[word[index] - 'a'] == NULL) {
                return false;
            }
            return searchPartten(p->next[word[index] - 'a'], word, index + 1);
        }
    }

   private:
    Tree trie;
};

int main() {
    WordDictionary w;
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("mad");
    cout << w.search("pad") << endl;
    cout << w.search("bad") << endl;
    cout << w.search(".ad") << endl;
    cout << w.search("b..") << endl;
    // cout << w.search("") << endl;
}