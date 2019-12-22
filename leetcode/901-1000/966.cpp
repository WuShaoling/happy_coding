#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        map<string, vector<string>> mm;
        map<string, vector<string>>::iterator it;

        for (string str : wordlist) mm[getPattern(str)].push_back(str);

        vector<string> res;
        for (string querie : queries) {
            it = mm.find(getPattern(querie));
            if (it != mm.end())
                res.push_back(findStr(it->second, querie));
            else
                res.push_back("");
        }
        return res;
    }

   private:
    string getPattern(string str) {
        char ch[5005];

        for (int i = 0; i < str.size(); i++) {
            char c = tolower(str[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ch[i] = '*';
            } else {
                ch[i] = c;
            }
        }

        return string(ch, ch + str.size());
    }

    string findStr(vector<string>& wordlist, string querie) {
        string res = "";

        string querieLower = querie;
        transform(querieLower.begin(), querieLower.end(), querieLower.begin(),
                  ::tolower);

        for (int i=wordlist.size()-1; i>=0; i--) {
            if (wordlist[i] == querie) return querie;

            string t = wordlist[i];
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            if (t == querieLower) res = wordlist[i];
        }

        if (res.size() != 0) return res;
        return wordlist[0];
    }
};

int main() {
    Solution s;
    vector<string> wordlist = {"yEllow"};
    vector<string> queries = {"yellow"};
    vector<string> res = s.spellchecker(wordlist, queries);
    for (string str : res) cout << str << endl;
};