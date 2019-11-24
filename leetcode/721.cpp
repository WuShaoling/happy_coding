#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;


class Solution {    //账户合并---并查集+STL
private:

public:
    vector<int> bb; //并查集bb

    int getroot(int x){
        if(x != bb[x]) 
            bb[x] = getroot(bb[x]);
        return bb[x];
    }

    void mergeAccount(int x,int y){
        x = getroot(x);
        y = getroot(y);
        if(x != y) 
            bb[y] = x;
    }

    vector<vector<string> > accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string> > reaccounts;  //返回合并后的账户集
        int n = accounts.size();

        if (n == 0) 
            return reaccounts;

        //初始化并查集和优先集
        for (int i = 0; i < n; i++){
            bb.push_back(i);//初始化每组的父亲为行号
        }
        
        map<string,int> m;  //邮箱和行号的映射
        for (int i = 1; i < accounts[0].size(); i++){   //添加第一行邮箱
            m[accounts[0][i]] = 0;  //初始化第一行邮箱的父亲行号为0
        }

        //先初始化第一行，然后从第二行开始，判断是否有重复，逐行将邮箱往m中添加
        for(int i = 1;i < n;i++){
            for(int j = 1;j < accounts[i].size();j++){
                if(m.find(accounts[i][j]) != m.end()){
                    mergeAccount(m[accounts[i][j]],i);  //重复则合并值为父亲行号
                }else{
                    m[accounts[i][j]] = i;//如果不重复，插入,设值为该行号
                }
            }
        }//至此找出了邮箱和对应行号的关系，确保了唯一性，接着找出邮箱和人的确定集合

        map<int, vector<string> > man;   //姓名+邮箱的 账户集合
        for (auto &it:m){    //遍历邮箱和行号的 映射集合
            int k = getroot(it.second);
            if (man.find(k) == man.end()){   //没有该账户时才新增账户
                man[k].push_back(accounts[k][0]);
            }
            man[k].push_back(it.first); //添加邮箱到集合
        }
        for(auto it:man) 
            reaccounts.push_back(it.second);    //添加每个账户
        return reaccounts;
    }
};
// class Solution {
// public:
//     vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
//         for(int i=0; i<accounts.size(); i++){
//             merge(accounts[i]);
//         }

//         map<string, set<string> > temp;
//         for(map<string, string>::iterator it=F.begin(); it!=F.end(); it++){
//             string f = find(it->second);
//             temp[f].insert(it->first);
//         }

//         vector<vector<string> > res;
//         for(map<string, set<string> >::iterator it=temp.begin(); it!=temp.end(); it++){
//             vector<string> t;
//             t.push_back(name[it->first]);
//             for(set<string>::iterator it1=it->second.begin(); it1!=it->second.end(); it1++){
//                 t.push_back(*it1);
//             }
//             res.push_back(t);
//         }

//         return res;
//     }

//     void merge(vector<string> s){
//         sort(s.begin()+1, s.end());

//         string cur_fa = s[1];
//         name[cur_fa] = s[0];

//         for(int i=1; i<s.size(); i++){
//             string ss = s[i];

//             // 如果之前不存在这个邮箱，初始化
//             if(F.count(ss) == 0){
//                 F[ss] = cur_fa;
//                 continue;
//             }

//             // 如果存在邮箱，说明可以合并
//             string fa = find(ss);
//             F[fa] = cur_fa;
//             F[ss] = cur_fa;
//         }
//     }

//     void show(){
//         cout << "show()" << endl;
//         for(map<string, string>::iterator it=F.begin(); it!=F.end(); it++){
//             cout << it->first << " " << it->second << endl;
//         }
//         cout << endl;
//     }

//     string find(string s){
//         if(F[s] == s){
//             return s;
//         }else{
//             F[s] = find(F[s]);
//             return F[s];
//         }
//     }
// private:
//     map<string, string> F;
//     map<string, string> name;
// };

int main(){

    vector<vector<string> > accounts = {
        {"David","David0@m.co","David1@m.co"},
        {"David","David3@m.co","David4@m.co"},
        {"David","David4@m.co","David5@m.co"},
        {"David","David2@m.co","David3@m.co"},
        {"David","David1@m.co","David2@m.co"}
    };

    Solution s;
    vector<vector<string> > res = s.accountsMerge(accounts);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}