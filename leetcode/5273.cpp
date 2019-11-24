#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef struct TrieNode {
    int count;
    string value;
    TrieNode* next[26] = {NULL};
    TrieNode() {
        count = 0;
        value = "";
    }
} * Trie;

class Solution {
   public:
    vector<vector<string> > suggestedProducts(vector<string>& products,
                                              string searchWord) {
        vector<vector<string> > res;

        sort(products.begin(), products.end());
        Trie root = new TrieNode();
        for (int i = 0; i < products.size(); i++) {
            buildTrie(root, products[i]);
        }

        for (int i = 0; i < searchWord.size(); i++) {
            res.push_back(search(root, searchWord.substr(0, i + 1)));
        }

        return res;
    }

    vector<string> search(Trie root, string word) {
        Trie p = root;
        vector<string> res;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] == NULL) return res;
            p = p->next[index];
        }
        int n = 0;
        dfs(p, res, &n);
        return res;
    }

    void dfs(Trie root, vector<string>& res, int* n) {
        if (root == NULL || *n > 2) return;

        if (root->value != "") {
            for (int i = 0; i < root->count; i++) {
                res.push_back(root->value);
                if (++(*n) > 2) {
                    return;
                }
            }
        }

        Trie p = root;
        for (int i = 0; i < 26; i++) {
            if (p->next[i] != NULL) {
                dfs(p->next[i], res, n);
            }
        }
    }

    void buildTrie(Trie root, string node) {
        Trie p = root;
        for (int i = 0; i < node.size(); i++) {
            int index = node[i] - 'a';
            if (p->next[index] == NULL) {
                p->next[index] = new TrieNode();
            }
            p = p->next[index];
        }
        p->value = node;
        p->count++;
    }
};
int main() {
    Solution s;
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor",
                               "mousepad"};
    string searchWord = "mouse";

    vector<vector<string> > res = s.suggestedProducts(products, searchWord);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ",";
        }
        cout << endl;
    }
}