#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct TrieNode {
    int count;
    bool leaf;
    TrieNode* next[26] = {NULL};
    TrieNode() {
        count = 0;
        leaf = true;
    }
} * Trie;

class Solution {
   public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trie = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            buildTrie(trie, words[i]);
        }
    }

    void f(Trie cur, Trie root){
        
    }

    void buildTrie(Trie root, string word) {
        Trie p = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] == NULL) {
                p->next[index] = new TrieNode();
            }
            p = p->next[index];
        }
        p->count++;
        p->leaf = true;
    }

   private:
    Trie trie;
};

int main() {}