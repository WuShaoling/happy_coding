#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct TrieNode {
    TrieNode* next[26] = {NULL};
    int leaf;
    TrieNode() { leaf = 0; }
} * Trie;

Trie buildTrie(vector<string>& words) {
    Trie root = new TrieNode();
    for (string word : words) {
        Trie p = root;
        for (char c : word) {
            int index = c - 'a';
            if (p->next[index] == NULL) {
                p->next[index] = new TrieNode();
            }
            p = p->next[index];
        }
        p->leaf++;
    }
    return root;
}

void addWord(Trie root, string& word) {
    Trie p = root;
    for (char c : word) {
        int index = c - 'a';
        if (p->next[index] == NULL) {
            p->next[index] = new TrieNode();
        }
        p = p->next[index];
    }
    p->leaf++;
}

void deleteWord(Trie root, string& word) {
    Trie p = root;
    for (char c : word) {
        int index = c - 'a';
        if (p->next[index] == NULL) {
            return;
        }
        p = p->next[index];
    }
    p->leaf--;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> words(k);
    vector<bool> flag(k, true);

    for (int i = 0; i < k; i++) {
        cin >> words[i];
    }

    Trie root = buildTrie(words);
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op[0] == '+') {
            string substr = op.substr(1, op.size() - 1);
            int index = stoi(substr) - 1;
            if (flag[index] == false) {
                flag[index] = true;
                addWord(root, words[index]);
            }
        } else if (op[0] == '-') {
            string substr = op.substr(1, op.size() - 1);
            int index = stoi(substr) - 1;
            if (flag[index] == true) {
                flag[index] = false;
                deleteWord(root, words[index]);
            }
        } else if (op[0] == '?') {
            string substr = op.substr(1, op.size() - 1);
            int ans = 0;
            for (int j = 0; j < substr.size(); j++) {
                Trie p = root;
                for (int kk = j; kk < substr.size(); kk++) {
                    int index = substr[kk] - 'a';
                    if (p->next[index]) {
                        ans += p->next[index]->leaf;
                        p = p->next[index];
                    } else {
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}