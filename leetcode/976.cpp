#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for(int i=A.size()-1; i>=2; i--){
            if(A[i-1]+A[i-2]>A[i]){
                return A[i-1]+A[i-2]+A[i];
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(2);
    v1.push_back(3);
    
    cout << solution.largestPerimeter(v1);
    
    return 0;
}
