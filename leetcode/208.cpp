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

class Trie {
   public:
    /** Initialize your data structure here. */
    Trie() { tree = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Tree p = tree;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            // cout << index << " " << word[i] << endl;
            if (p->next[index] == NULL) {
                p->next[index] = new TrieNode();
            }
            p = p->next[index];
        }
        p->leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        // cout << "search" << endl;
        Tree p = tree;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] != NULL) {
                p = p->next[index];
            } else {
                return false;
            }
        }
        return p->leaf;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        Tree p = tree;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (p->next[index] != NULL) {
                p = p->next[index];
            } else {
                return false;
            }
        }
        return true;
    }

   private:
    Tree tree;
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.startsWith("app") << endl;
}