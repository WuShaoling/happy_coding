#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct TrieNode {
    string value;
    TrieNode* next[26] = {NULL};
    TrieNode() { value = ""; }
} * Trie;

class Solution {
   public:
    Solution() { trie = new TrieNode(); }

    string replaceWords(vector<string>& dict, string sentence) {
        for (int i = 0; i < dict.size(); i++) {
            buildTrie(trie, dict[i]);
        }

        vector<string> words = split(sentence);

        string res = "";
        for (int i = 0; i < words.size(); i++) {
            string sear = search(words[i]);
            if ("" == sear) {
                res += " " + words[i];
            } else {
                res += " " + sear;
            }
        }
        if (res == "") return res;
        return res.substr(1, res.size());
    }

   private:
    string search(string word) {
        Trie p = trie;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->next[index] == NULL) {
                return p->value;
            }
            if (p->value != "") {
                return p->value;
            }
            p = p->next[index];
        }
        return p->value;
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
        p->value = word;
    }

    vector<string> split(const string& str) {
        vector<string> res;
        if ("" == str) return res;

        char* strs = new char[str.length() + 1];
        strcpy(strs, str.c_str());

        char* p = strtok(strs, " ");
        while (p) {
            string s = p;
            res.push_back(s);
            p = strtok(NULL, " ");
        }

        return res;
    }

    Trie trie;
};

int main() {
    Solution s;
    vector<string> words = {"cat", "bat", "rat"};
    cout << s.replaceWords(words, "the cattle was rattled by the battery");
}