#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &str, const char pattern) {
    vector<string> res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern)) {
        res.push_back(temp);
    }
    return res;
}