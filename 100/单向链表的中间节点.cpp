/**
* 题目描述
求单向链表中间的节点值，如果奇数个节点取中间，偶数个取偏右边的那个值。

输入描述：
第一行 链表头节点地址path 后续输入的节点数n
后续输入每行表示一个节点，格式:   "节点地址  节点值  下一个节点地址(-1表示空指针)“
输入保证链表不会出现环，并且可能存在一些节点不属于链表。

输出描述：
链表中间节点值。

测试用例:
输入:
00010 4
00000 3 -1
00010 5 12309
11451 6 00000
12309 7 11451
输出:
6
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val; int next;
    ListNode(int _val, int _next): val(_val), next(_next){}
};

int main(){
    int headAddr, n;  // 头节点的位置，节点的数量
    cin >> headAddr >> n;

    unordered_map<int, ListNode*>umap;
    for (int i = 0; i < n; ++i) {
        int addr, val, next;
        cin >> addr >> val >> next;
        umap[addr] = new ListNode(val, next);
    }

    int size = 1, cur = 0;
    ListNode* head = umap[headAddr];
    ListNode* node = head;
    // 统计有效节点的数量
    while(node->next != -1){
        node = umap[node->next]; size++;
    }

    // 找到中间节点
    while (head->next != -1){
        if((size / 2) == cur){
            cout << head->val;
            return 0;
        }
        head = umap[head->next];
        cur++;
    }
    return 0;
}