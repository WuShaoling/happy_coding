#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int result = 0;
        for(int i=0; i<A.size(); i++){
            int sum = 0;
            for(int j=i; j<A.size(); j++){
                sum+=A[j];
                if(sum % K == 0){
                    result++;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    
    vector<int> v1;
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(0);
    v1.push_back(-2);
    v1.push_back(-3);
    v1.push_back(1);
    
    cout << solution.subarraysDivByK(v1, 5);
    
    return 0;
}
