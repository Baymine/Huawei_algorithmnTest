/**
羊、狼、农夫都在岸边，当羊的数量小于狼的数量时，狼会攻击羊，农夫则会损失羊。农夫有一艘容量固定的船，能够承载固定数量的动物。
要求求出不损失羊情况下将全部羊和狼运到对岸需要的最小次数。只计算农夫去对岸的次数，回程时农夫不会运送羊和狼。

备注：农夫在或农夫离开后羊的数量大于狼的数量时狼不会攻击羊。
农夫自身不占用船的容量。

输入描述
第一行输入为M，N，X， 分别代表羊的数量，狼的数量，小船的容量。

输出描述
输出不损失羊情况下将全部羊和狼运到对岸需要的最小次数。

（若无法满足条件则输出0）
 */


/** 算法思路： 深度优先遍历
 *  将所有的可能的运输方案进行遍历，如果满足此岸和彼岸的条件（羊狼数量的限制），那么就进行递归（相当于一次运输）
 */
#include <bits/stdc++.h>
using namespace std;
int res = INT_MAX;

void dfs(int curSheep, int curWolf, int opSheep, int opWolf, int times, int cap){
    if(times >= res) return;  // 剪枝
    if (curSheep + curWolf <= cap){  // 剩余的一次性可以运完
        res = min(res, times + 1);
        return;
    }


    for (int i = 0; i <= curSheep && i <= cap; ++i) {
        for (int j = 0; j <= curWolf && i + j <= cap; ++j) {
            if(i + j == 0) continue;

            // 运送之后，此岸和彼岸的狼羊的情况
            if(((curSheep - i == 0) || (curSheep - i > curWolf - j)) &&
                    (opSheep + i > opWolf + j)){
                dfs(curSheep - i, curWolf - j, opSheep + i, opWolf + j, times + 1, cap);
            }
        }
    }
}

int main(){
    int sheep, wolves, cap;
    cin >> sheep >> wolves >> cap;
    dfs(sheep, wolves, 0, 0, 0, cap);
    cout << (res == INT_MAX ? 0 : res) << endl;

    return 0;
}

