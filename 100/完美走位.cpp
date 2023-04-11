/**一、题目
输入一个长度为4的倍数的字符串，字符串中仅包含WASD四个字母。
将这个字符串中的连续子串用同等长度的仅包含WASD的字符串替换，
 如果替换后整个字符串中WASD四个字母出现的频数相同，那么我们称替换后的字符串是“完美走位”。
求子串的最小长度。

如果输入字符串已经平衡则输出0。

二、输入
一行字符表示给定的字符串s
数据范围：
1<=n<=10^5且n是4的倍数，字符串中仅包含WASD四个字母。

三、输出
一个整数表示答案

四、样例输入输出
示例1：
输入：
WASDAASD
输出：
1
说明：
将第二个A替换为W，即可得到完美走位 。

示例2：
输入：
AAAA
输出：
3
说明：
将其中三个连续的A替换为WSD，即可得到完美走位
 *
 */
#include <bits/stdc++.h>
using namespace  std;
bool cmp(map<char, int>&ori, map<char, int>&window){
    for (auto p: ori) {
        if(window[p.first] != p.second) return false;
    }
    return true;
}

bool isNull(map<char, int>&m){
    for (auto p: m) {
        if(p.second != 0) return false;
    }
    return true;
}

int main() {

    // 处理输入
    string input_str;
    cin >> input_str;
    map<char, int> char_count;
    for (auto x: input_str) {
        if (char_count.count(x)) {
            char_count[x] += 1;
        } else {
            char_count[x] = 1;
        }
    }

    // 特殊情况
    if (char_count['W'] == char_count['A'] &&
        char_count['W'] == char_count['S'] &&
        char_count['W'] == char_count['D']) {
        cout << 0;
        return 0;
    }

    // 统计需要删除的字符及其个数
    map<char, int>deleteChar;
    int numOfDeleteChars = 0;
    for (auto p: char_count) {
        if(p.second > input_str.size() / 4) {
            deleteChar[p.first] += p.second - input_str.size()/4;
            numOfDeleteChars++;
        }
    }

    // 利用滑动窗口，检查窗口内的元素是否满足要删除的字符的个数
    int left = 0, right = 0;
    map<char, int>windowChar;
    int res  = INT_MAX;
    while(right < input_str.size()) {
        if(right - left >= numOfDeleteChars - 1 && cmp(deleteChar, windowChar)) {  // 发现匹配
            res = min(res, right - left);
//            cout << res << " " << right << " " << left << endl;

            while(left < right && cmp(deleteChar, windowChar)) {
                windowChar[input_str[left]]--;
                left++;
            }
        }
        windowChar[input_str[right]] += 1;
        right++;
    }
    cout << res;
    return 0;

}


// ----------------------------------  网络题解
//#include <bits/stdc++.h>
//using namespace  std;
//
//int main(){
//
//    // 处理输入
//    string input_str ;
//    cin >> input_str;
//    map<char, int> char_count;
//    for (auto x : input_str) {
//        if (char_count.count(x)) {
//            char_count[x] +=1;
//        } else {
//            char_count[x] =1;
//        }
//    }
//
//    // 特殊情况
//    if (char_count['W'] == char_count['A']  &&
//        char_count['W'] == char_count['S']  &&
//        char_count['W'] == char_count['D']) {
//        cout << 0;
//        return 0;
//    }
//
//    // 左右区间位置
//    int left = 0;
//    int right = 0;
//    int length = 0;
//
//    // 替换的最小长度
//    int res = input_str.size();
//    // 出现次数最多的字母
//    int max_char_num = 0;
//    // 可替换字母个数, 随着指针移动，如果free_char_num 大于0且能被4整除，当前范围满足条件，左指针右移一格，否则右指针右移
//    int free_char_num = 0;
//
//    char_count[input_str[0]]--;
//    while (true)
//    {
//        max_char_num = max({char_count['W'], char_count['S'], char_count['A'], char_count['D']});
//        length = right - left + 1;
//        free_char_num = length - ((max_char_num - char_count['W']) + (max_char_num - char_count['S'])
//                + (max_char_num - char_count['A']) + (max_char_num - char_count['D']));
//
//        // 先判断能否通过替换区间内的元素使 WASD 数量一致，再判断剩余位置是否是４的倍数。
//        if (free_char_num >= 0 && free_char_num % 4 == 0){  // 满足条件
//            if(length<res) {
//                res = length;
//            }
//            char_count[input_str[left]]++;   // 这里相当于统计在窗口之外的各个字符的个数
//            left++;
//        } else {   // 不满足条件
//            right++;
//            char_count[input_str[right]]--;
//        }
//        if (right >= input_str.size())// 越界即结束
//            break;
//    }
//    cout << res;



//    string input_str;
//    cin >> input_str;
//    unordered_map<char, int>char_count;
//
//    for (char x: input_str) {
//        char_count[x] += 1;
//    }
//
////    for (auto p: char_count) {
////        cout << p.first << ": " << p.second << endl;
////    }
//
//    bool isPerfect = true;
//    for (auto p: char_count) {
//        if(p.second != input_str.size() / 4){
//            isPerfect = false;
//            break;
//        }
//    }
//    if(isPerfect) {
//        cout << 0; return 0;
//    }
//
//    int left = 0, right = 0, len = 0;
//    int res = input_str.size();
//    int maxCharNum = 0; // 出现次数最多的字母
//    int freeCharNum = 0; // 可替换字母个数
//
//    char_count[input_str[0]]--;
//
//    while (true){
//        maxCharNum = max({char_count['W'], char_count['S'], char_count['A'], char_count['D']});
//        len = right - left + 1;
//        freeCharNum = len - ((maxCharNum - char_count['W']) + (maxCharNum - char_count['S'])
//                        + (maxCharNum - char_count['A']) + (maxCharNum - char_count['D']));
//    }


//}
