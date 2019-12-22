// #include <iostream>
// #include <vector>
// #include <math.h>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {

//         sort(nums.begin(), nums.end());

//         int res = nums[0]+nums[1]+nums[2];
//         // 固定第1个数
//         for(int k=0; k<nums.size()-2; k++){
//             for(int i=k+1, j=nums.size()-1; i<j; ){
                
//                 int sum = nums[i]+nums[j]+nums[k];

//                 if(sum<target){
//                     i++;
//                 }else if(sum>target){
//                     j--;
//                 }else{
//                     return sum;
//                 }
//                 if(abs(sum-target) < abs(res-target)){
//                     res = sum;
//                 }
//             }
//         }

//         return res;
//     }
// };

// int main(){
//     Solution solution;
//     // 1,8,6,2,5,4,8,3,7
//     vector<int> v;
//     solution.threeSumClosest(v, 1);
// }

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int res = nums[0]+nums[1]+nums[2];
        // 固定第1个数
        for(int k=0; k<nums.size()-2; k++){

            // if (k>0 && nums[k] == nums[k-1]) continue;

            for(int i=k+1, j=nums.size()-1; i<j; ){
                
                int sum = nums[i]+nums[j]+nums[k];

                if(sum<target){
                    i++;
                    while(i<j && nums[i] == nums[i-1]) i++;
                }else if(sum>target){
                    j--;
                    while(i<j && nums[i] == nums[j+1]) j--;
                }else{
                    return sum;
                }
                if(abs(sum-target) < abs(res-target)){
                    res = sum;
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
    solution.threeSumClosest(v, 1);
}