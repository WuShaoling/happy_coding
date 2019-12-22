#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        
        vector<vector<int> > res;
        if(nums.empty() || nums.size() < 4){
            return res;
        }

        sort(nums.begin(), nums.end());

        // 固定第1个数
        for(int first=0; first<nums.size()-3; first++){
            
            // 头部去重
            if (first>0 && nums[first] == nums[first-1]) continue;

            // 固定第2个数
            for(int second=first+1; second<nums.size()-2; second++){
                // 头部去重
                if (second>first+1 && nums[second] == nums[second-1]) continue;
                
                int left = target-nums[first]-nums[second];
                for(int i=second+1, j=nums.size()-1; i<j; ){
                    if(nums[i]+nums[j]>left){
                        j--;
                    }else if(nums[i]+nums[j]<left){
                        i++;
                    }else{
                        res.push_back({nums[first], nums[second], nums[i], nums[j]});
                        i++, j--;
                        while(i<j && nums[i] == nums[i-1]) i++;
                        while(i<j && nums[i] == nums[j+1]) j--;
                    }
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
    solution.fourSum(v, 0);
}