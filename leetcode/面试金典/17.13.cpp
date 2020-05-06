#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct Node {
    Node* next[26] = {NULL};
    bool leaf;
    Node() { leaf = false; }
} * Trie;

class Solution {
   public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> memo = vector<int>(1005, -1);
        Trie root = buildTrie(dictionary);
        return backtrack(root, memo, dictionary, sentence, 0);
    }

   private:
    Trie buildTrie(vector<string>& dictionary) {
        Trie root = new Node();
        for (string word : dictionary) {
            Trie p = root;
            for (char c : word) {
                int index = c - 'a';
                if (p->next[index] == NULL) p->next[index] = new Node();
                p = p->next[index];
            }
            p->leaf = true;
        }
        return root;
    }

    int backtrack(Trie root, vector<int>& memo, vector<string>& dictionary,
                  string& sentence, int start) {
        if (start >= sentence.size()) return 0;
        if (memo[start] != -1) return memo[start];

        int ans = sentence.size() - start;
        for (int i = start; i < sentence.size(); i++) {
            Trie p = root;
            for (int j = i; j < sentence.size(); j++) {
                int idx = sentence[j] - 'a';
                if (p->next[idx]) {
                    if (p->next[idx]->leaf) {
                        int subCount =
                            backtrack(root, memo, dictionary, sentence, j + 1);
                        ans = min(ans, subCount + (i - start));
                    }
                    p = p->next[idx];
                } else {
                    break;
                }
            }
        }

        memo[start] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> dictionary = {"looked", "just", "like", "her", "brother"};
    string sentence = "jesslookedjustliketimherbrother";
    cout << s.respace(dictionary, sentence) << endl;
}