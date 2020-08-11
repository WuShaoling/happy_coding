#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int newGamerId;
    vector<vector<int>> newGamer(n + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < n; i++) {
        cin >> newGamerId;
        // 不保存新玩家的ID，数组的下标即新玩家的ID
        for (int j = 0; j < n; j++) {
            cin >> newGamer[newGamerId][j];
        }
    }

    int oldGamerId;
    vector<vector<int>> oldGamer(n + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < n; i++) {
        cin >> oldGamerId;
        // 不保存老玩家的ID，数组的下标即老玩家的ID
        for (int j = 0; j < n; j++) {
            cin >> oldGamer[oldGamerId][j];
        }
    }

    vector<bool> newGamerFlag(n + 1, false);
    vector<bool> oldGamerFlag(n + 1, false);
    vector<pair<int, int>> ans;

    // 对于每一列
    for (int col = 0; col < n; col++) {
        // 行号即新玩家的ID
        for (int row = 1; row <= n; row++) {
            // 新玩家已经匹配完了，直接处理下一个新玩家
            if (newGamerFlag[row] == true) {
                continue;
            }

            int oldGamerId = newGamer[row][col];
            // 对于当前这个新玩家(id即上面的row)来说，优先级最高的老玩家已经匹配完了，只能等下一列了
            if (oldGamerFlag[oldGamerId] == true) {
                continue;
            }

            // 先拿到老玩家对应的新玩家列表
            vector<int> oldGamerToNewGamer = oldGamer[oldGamerId];

            // 对于当前这个老玩家，找第一个未绑定老玩家的新玩家的ID，如果这个ID等于
            // 当前这个新玩家的ID(row)，那么当前这个新玩家可以匹配，因为他的优先级最高
            for (int newGamerId : oldGamerToNewGamer) {
                if (newGamerFlag[newGamerId] == true) continue;
                // 找到了可以和当前老玩家绑定的新玩家
                if (newGamerId == row) {  // 如果ID相同，那么可以绑定
                    ans.push_back({newGamerId, oldGamerId});
                    oldGamerFlag[oldGamerId] = true;
                    newGamerFlag[newGamerId] = true;
                    break;
                } else {  // 如果这个老玩家可以绑定的新玩家的ID不是当前这个新玩家，
                          // 那么直接终止这层循环，当前新玩家只能继续等下一列
                    break;
                }
            }
        }
    }

    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }
}
/*

3
1 2 3 1
2 1 3 2
3 1 2 3
1 1 2 3
2 1 2 3
3 1 2 3

*/