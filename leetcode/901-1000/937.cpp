#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(string &a, string &b){
        string aa = a.substr(a.find_first_of(" ")+1, a.size());
        string bb = b.substr(b.find_first_of(" ")+1, b.size());
        if(aa > bb){
            return 1;
        }
        return 0;
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<string> number;
        priority_queue<string, vector<string>, cmp> alpha;
        for(int i=0; i<logs.size(); i++){
            unsigned long n = logs[i].find_first_of(" ")+1;
            if(logs[i][n] >= '0' && logs[i][n] <= '9'){
                number.push_back(logs[i]);
            } else{
                alpha.push(logs[i]);
            }
        }
        while(!alpha.empty()){
            res.push_back(alpha.top());
            alpha.pop();
        }
        for (int i=0; i<number.size(); i++){
            res.push_back(number[i]);
        }
        return res;
    }
};

int main(){
    Solution solution;
    
    vector<string> v1;
    v1.push_back("a1 9 2 3 1");
    v1.push_back("g1 act car");
    v1.push_back("zo4 4 7");
    v1.push_back("ab1 off key dog");
    v1.push_back("a8 act zoo");
    
    vector<string> res = solution.reorderLogFiles(v1);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    
    return 0;
    
}
