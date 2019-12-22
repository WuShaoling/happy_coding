#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        vector<vector<int> > res;
        if(nums.empty() || nums.size() < 3){
            return res;
        }

        sort(nums.begin(), nums.end());

        // 固定第1个数
        for(int k=0; k<nums.size()-2; k++){
            // 头部去重
            if (k>0 && nums[k] == nums[k-1]) continue;
            if (nums[k] > 0) break;
            
            for(int i=k+1, j=nums.size()-1; i<j; ){
                if(nums[i]+nums[j]+nums[k] > 0){
                    j--;
                }else if(nums[i]+nums[j]+nums[k] < 0){
                    i++;
                }else{
                    res.push_back({nums[k], nums[i], nums[j]});
                    i++, j--;
                    while(i<j && nums[i] == nums[i-1]) i++;
                    while(i<j && nums[i] == nums[j+1]) j--;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution solution;
    // 1,8,6,2,5,4,8,3,7
    vector<int> v;
    solution.threeSum(v);
}