#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return {};

        vector<int> res(T.size(), 0);
        stack<int> st;
        for (int i = 0; i < T.size(); i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int t = st.top();
                st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                auto t = st.top();
                st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};

// class Solution {
//    public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         vector<int> res(T.size(), 0);

//         int index[101];
//         for (int i = 0; i < 101; i++) index[i] = INT_MAX;

//         for (int i = T.size() - 1; i >= 0; i--) {
//             int warmer_index = INT_MAX;
//             for (int j = T[i] + 1; j <= 100; j++) {
//                 if (index[j] < warmer_index) warmer_index = index[j];
//             }
//             if (warmer_index != INT_MAX) res[i] = warmer_index - i;
//             index[T[i]] = i;
//         }
//         return res;
//     }
// };

int main() {
    Solution s;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s.dailyTemperatures(T);
    for (int i : res) cout << i << " ";
    cout << endl;
}
