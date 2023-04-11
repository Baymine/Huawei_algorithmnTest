/**
给定一个字符串s，s包括以空格分隔的若干个单词，请对s进行如下处理后输出：
1、单词内部调整：对每个单词字母重新按字典序排序
2、单词间顺序调整：
1）统计每个单词出现的次数，并按次数降序排列
2）次数相同，按单词长度升序排列
3）次数和单词长度均相同，按字典升序排列
请输出处理后的字符串，每个单词以一个空格分隔。

输入描述：
一行字符串，每个字符取值范围：【a-z，A-Z，0-9】以及空格，字符串长度范围：【1，1000】

例1：
输入
This is an apple
输出
an is This aelpp

例2：
输入：
My sister is in the house not in the yard

输出：
in in eht eht My is not adry ehosu eirsst
*
*/

// 算法思路： 按照题目模拟即可
#include <bits/stdc++.h>
using namespace std;

int main(){
    string inputString;
    getline(cin, inputString);
    stringstream ss(inputString);
    vector<string>strs;
    string temp;
    while (ss >> temp) strs.push_back(temp);

//    for (auto& s: strs) {
//        cout << s << " ";
//    }

    unordered_map<string, int>vocabularyCount;
    // 第一个要求：对单词内部进行调整
    for (string& s: strs) {
        sort(s.begin(), s.end());

        vocabularyCount[s] += 1;   // 统计单词出现的次数
    }

    // 单词间的调整
    sort(strs.begin(), strs.end(), [&](string& s1, string& s2){
        if(vocabularyCount[s1] != vocabularyCount[s2]) return vocabularyCount[s1] > vocabularyCount[s2];
        if(s1.size() != s2.size()) return s1.size() < s2.size();
        return s1 < s2;
    });

    for (int i = 0; i < strs.size(); ++i) {
        if(i != strs.size() - 1) cout << strs[i] << " ";
        else cout << strs[i];
    }

}

