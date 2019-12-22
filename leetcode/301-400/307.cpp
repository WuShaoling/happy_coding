// #include <iostream>
// #include <algorithm>

// using namespace std;

// class NumArray {
// public:
//     NumArray(vector<int>& nums){
//         nums = nums;
//     }
    
//     void update(int i, int val);
    
//     int sumRange(int i, int j) {
//         if(i >= this->nums.size()){
//             return 0;
//         }
//         if(j >= this->nums.size()){
//             j = this->nums.size()-1;
//         }
//         int sum = 0;
//         for(;i<=j;i++){
//             sum += nums[i];
//         }
//         return sum;
//     }
// private:
//     vector<int> nums;
// };

// void NumArray::update(int i, int val){
//     if(i < this->nums.size()){
//         nums[i] = val;
//     }
// }

// int main(){

// }