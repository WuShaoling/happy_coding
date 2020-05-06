#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct TrieNode {
    TrieNode* next[26] = {NULL};
    bool leaf;
    TrieNode() : leaf(false) {}
} * Trie;

class Solution {
   public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        if (big.size() == 0) {
            res.resize(smalls.size());
            return res;
        }

        Trie trie = new TrieNode();
        for (string str : smalls) buildTrie(trie, str);

        for (int i = 0; i < big.size(); i++) {
            find(trie, big.substr(i, big.size() - i), i);
        }

        for (string str : smalls) res.push_back(mm[str]);

        return res;
    }

   private:
    void find(Trie root, string str, int index) {
        Trie p = root;
        int i = 0;
        for (char c : str) {
            int pos = c - 'a';
            if (p->next[pos]) {
                if (p->next[pos]->leaf)
                    mm[str.substr(0, i + 1)].push_back(index);
                p = p->next[pos];
                i++;
            } else {
                return;
            }
        }
    }

    void buildTrie(Trie root, string str) {
        Trie p = root;
        for (char c : str) {
            int index = c - 'a';
            if (p->next[index] == NULL) p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->leaf = true;
    }

    unordered_map<string, vector<int>> mm;
};

// typedef struct TrieNode {
//     TrieNode* next[26] = {NULL};
//     vector<int> pos;
//     TrieNode() {}
// } * Trie;

// class Solution {
//    public:
//     vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
//         vector<vector<int>> res;
//         if (big.size() == 0) {
//             res.resize(smalls.size());
//             return res;
//         }

//         Trie trie = new TrieNode();
//         for (int i = 0; i < big.size(); i++) {
//             buildTrie(trie, big.substr(i, big.size() - i), i);
//         }

//         for (string small : smalls) {
//             res.push_back(find(trie, small));
//         }

//         return res;
//     }

//     vector<int> find(Trie root, string small) {
//         vector<int> res;
//         if (small.size() == 0) return res;

//         Trie p = root;
//         for (char c : small) {
//             int pos = c - 'a';
//             if (p->next[pos]) {
//                 p = p->next[pos];
//             } else {
//                 return res;
//             }
//         }
//         return p->pos;
//     }

//     void buildTrie(Trie root, string str, int pos) {
//         Trie p = root;
//         for (char c : str) {
//             int index = c - 'a';
//             if (p->next[index] == NULL) {
//                 p->next[index] = new TrieNode();
//             }
//             p->next[index]->pos.push_back(pos);
//             p = p->next[index];
//         }
//     }
// };

int main() {
    Solution s;
    vector<string> smalls = {"is", "aaaaa", "hi", "sis", "i", "ssippi"};
    vector<vector<int>> res = s.multiSearch("mississippi", smalls);
    for (vector<int> line : res) {
        for (int i : line) cout << i << " ";
        cout << endl;
    }
}