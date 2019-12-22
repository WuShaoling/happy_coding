#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mm;
        map<string, int>::iterator it;

        for (string cpdomain : cpdomains) {
            int n = cpdomain.find_first_of(" ");
            int num = atoi(cpdomain.substr(0, n).c_str());

            for (int i = n; i < cpdomain.size(); i++) {
                if (cpdomain[i] == '.' || cpdomain[i] == ' ') {
                    string domain =
                        cpdomain.substr(i + 1, cpdomain.size() - i - 1);
                    mm[domain] += num;
                }
            }
        }

        vector<string> res;
        for (it = mm.begin(); it != mm.end(); it++) {
            res.push_back(to_string(it->second) + " " +
                          it->first.substr(0, it->first.size()));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com",
                                "1 intel.mail.com", "5 wiki.org"};
    s.subdomainVisits(cpdomains);
}