#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        if (arr.empty()) return false;
        vector<bool> visited(arr.size(), false);
        return dfs(arr, visited, start);
    }

    bool dfs(vector<int>& arr, vector<bool>& visited, int start) {
        if (start >= arr.size() || start < 0 || visited[start]) return false;

        if (arr[start] == 0) return true;

        visited[start] = true;
        return dfs(arr, visited, start + arr[start]) ||
               dfs(arr, visited, start - arr[start]);
    }

    bool bfs(vector<int>& arr, vector<bool>& visited, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            start = q.front();
            q.pop();

            if (arr[start] == 0) return true;

            int left = start - arr[start];
            if (left >= 0 && left < arr.size() && !visited[left]) {
                q.push(left);
                visited[left] = true;
            }

            int right = start + arr[start];
            if (right >= 0 && right < arr.size() && !visited[right]) {
                q.push(right);
                visited[right] = true;
            }
        }
        return false;
    }
};

int main() {}