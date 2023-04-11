/**
* 给一个无向图染色，可以填红黑两种颜色，必须保证相邻两个节点不能同时为红色，输出有多少种不同的染色方案？

输入描述：
第一行输入M(图中节点数) N(边数)
后续N行格式为：V1 V2表示一个V1到V2的边。
数据范围：1 <= M <= 15,0 <= N <= M * 3，不能保证所有节点都是连通的。

输出描述：
输出一个数字表示染色方案的个数。

示例1：
输入：
4 4
1 2
2 4
3 4
1 3
输出：
7
说明：4个节点，4条边，1号节点和2号节点相连，2号节点和4号节点相连，3号节点和4号节点相连，1号节点和3号节点相连，若想必须保证相邻两个节点不能同时为红色，总共7种方案。
*/

// 需要学习这里的边的存储方式，这里用二进制位表示节点的情况，这样可以直接循环遍历所有情况，然后将不满足
// 条件的情况剔除即可
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;  // 节点数 + 边数
    cin >> m >> n;
    vector<pair<int, int>>edges;
    int node, edge;
    for (int i = 0; i < n; ++i) {
        cin >> node >> edge;
        edges.emplace_back(node, edge);
    }

    int count = 0;
    // 遍历所有组合的可能0 ~ 10000
    for (int i = 0; i < (1 << m); ++i) {
        bool flag = true;

        // 遍历所有邻接节点
        for (auto e: edges) {
            // 检查相邻节点之间是否是相同的颜色
            if (((i >> (m - e.first)) & 1) && ((i >> (m - e.second)) & 1)){
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }
    cout << count << endl;
    return 0;
}