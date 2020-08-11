#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 输入
    int n;
    cin >> n;
    getchar();
    vector<pair<string, string>> ta(n);
    for (int i = 0; i < n; i++) {
        cin >> ta[i].first >> ta[i].second;
    }

    // 先排序，排序以后后面处理 group by 的时候不用全部遍历了
    // 优先按照 username 升序排序，然后按照 tbaname 升序排序
    sort(ta.begin(), ta.end(),
         [](const pair<string, string>& a, const pair<string, string>& b) {
             if (a.second == b.second) {
                 return a.first < b.first;
             }
             return a.second < b.second;
         });

    // 求 group by
    // pair<string, string>, set<string> 对应
    // pair<tbaname1, tbaname2>, set<username>(对应distinct)
    map<pair<string, string>, set<string>> mm;
    for (int i = 0; i < n;) {
        // username 已经有序，不用从头找，直接从当前位置向前找
        for (int j = i - 1; j >= 0 && ta[j].second == ta[i].second; j--) {
            if (ta[j].first != ta[i].first) {
                mm[{ta[i].first, ta[j].first}].insert(ta[j].second);
            }
        }
        // 同理，从当前位置向后找
        for (int j = i + 1; j < n && ta[j].second == ta[i].second; j++) {
            if (ta[j].first != ta[i].first) {
                mm[{ta[i].first, ta[j].first}].insert(ta[j].second);
            }
        }
    }

    // 过滤掉 <= 2 的数据行
    // pair<pair<string, string>, int> 对应
    // pair<pair<tbaname1, tbaname2>, count>
    vector<pair<pair<string, string>, int>> res;
    for (auto it : mm) {
        if (it.second.size() > 2) {
            res.push_back({it.first, it.second.size()});
        }
    }

    // 求最后的 order by tbaname1, tbaname2
    sort(res.begin(), res.end(),
         [](const pair<pair<string, string>, int>& a,
            const pair<pair<string, string>, int>& b) {
             if (a.first.first == b.first.first) {
                 return a.first.second < b.first.second;
             }
             return a.first.first < b.first.first;
         });

    // 输出结果
    for (auto it : res) {
        cout << it.first.first << " " << it.first.second << " " << it.second
             << endl;
    }
}

/*
8
0 ccc Beal
1 ddd Beal
2 bbb Kate
3 ccc Kate
4 ddd Kate
5 ccc Tom
6 ddd Tom
7 eee Tom

这是排好序的，对于 Kate
来说，i=2，由于使用username做相等连接，所以内层循环只查找username相等的，username相等的一定集中在i前后(因为排好序了)，也就是从当前
i 相前向后出发即可，不用从头遍历一遍了

*/
