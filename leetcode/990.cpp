#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        if(equations.size() == 0){
            return true;
        }

        for(int i=0; i<26; i++){
            F.push_back(i);
        }

        for(int i=0; i<equations.size(); i++){
            if(equations[i][1] == '='){
                merge(equations[i]);
            }
        }

        for(int i=0; i<equations.size(); i++){
            if(equations[i][1] == '!'){
                if(getFather(equations[i][0]-'a') == getFather(equations[i][3]-'a')){
                    return false;
                }
            }
        }

        return true;
    }

    void merge(string s){
        
        int fx = getFather(s[0]-'a');
        int fy = getFather(s[3]-'a');

        if(fx != fy){
            if(fx < fy){
                F[fy] = fx;
            }else{
                F[fx] = fy;
            }
        }
    }

    int getFather(int s){
        if(F[s] == s){
            return s;
        }else{
            F[s] = getFather(F[s]);
            return F[s];
        }
    }

    void show(){
        for(int i=0; i<F.size(); i++){
            cout << (char)(i+'a') << " " << (char)(F[i]+'a') << endl;
        }
    }

private:
    vector<int> F;
};

int main(){
    Solution s;
    vector<string> equations = {"a==b","e==c","b==c","a!=e"};
    cout << s.equationsPossible(equations) << endl;
}