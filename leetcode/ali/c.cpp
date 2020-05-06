#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    // 初始化单向图
    vector<vector<long>> matrix(n + 1, vector<long>(n + 1, 1e10));
    for (int i = 0; i < n + 1; i++) {
        matrix[i][i] = 0;
    }

    // 输入 m 条边
    int r, c, d;
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d;
        matrix[r][c] = d;
    }

    // Floyd-Warshall算法
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

    long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (matrix[i][x] != 1e10 && matrix[x][i] != 1e10) {
            ans = max(ans, matrix[i][x] + matrix[x][i]);
        }
    }

    cout << ans << endl;
    return 0;
}

/*
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
*/