#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef struct Node {
    Node* next[26] = {NULL};
    bool leaf = false;
} * Trie;

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie root = buildTrie(words);

        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (inBoard(m, n, i, j)) backtrack(board, root, m, n, i, j, "");
            }
        }

        return paths;
    }

   private:
    void backtrack(vector<vector<char>>& board, Trie root, int m, int n, int x,
                   int y, string path) {
        if (!inBoard(m, n, x, y) || board[x][y] == 0) return;

        // 如果当前字符匹配字典树节点
        int idx = board[x][y] - 'a';
        if (root->next[idx]) {
            // 防止重复访问
            board[x][y] = 0;

            // 更新路径的值
            path.push_back('a' + idx);

            // 根节点即意味着这条路径找到了单词
            if (root->next[idx]->leaf) {
                paths.push_back(path);
                root->next[idx]->leaf = false;
            }

            // 沿着路径朝4个方向继续搜索
            for (int i = 0; i < 4; i++) {
                int nextX = dir[i][0] + x;
                int nextY = dir[i][1] + y;
                // 预先判断，减少递归调用次数
                if (inBoard(m, n, nextX, nextY) && board[nextX][nextY] != 0) {
                    backtrack(board, root->next[idx], m, n, nextX, nextY, path);
                }
            }

            // 恢复原值
            board[x][y] = 'a' + idx;
        }
    }

    bool inBoard(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    Trie buildTrie(vector<string>& words) {
        Trie root = new Node();
        Trie p;
        for (string word : words) {
            p = root;
            for (char c : word) {
                int idx = c - 'a';
                if (p->next[idx] == NULL) p->next[idx] = new Node();
                p = p->next[idx];
            }
            p->leaf = true;
        }
        return root;
    }

    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> paths;
};

int main() {}