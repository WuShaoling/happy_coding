#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;

        int r = 0;  // 多余的线缆
        for (vector<int> connection : connections) {
            int fa = find(arr, connection[0]);
            int fb = find(arr, connection[1]);
            if (fa != fb)
                arr[fa] = fb;
            else
                r++;
        }
        int t = 0;  // 连通图的个数
        for (int i = 0; i < n; i++) {
            if (i == find(arr, arr[i])) t++;
        }

        if (t - 1 > r) return -1;
        return t - 1;
    }

   private:
    int find(vector<int>& arr, int x) {
        if (arr[x] != x) arr[x] = find(arr, arr[x]);
        return arr[x];
    }
};

int main() {}