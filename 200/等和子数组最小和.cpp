/**
给定一个数组nums,将元素分为若干个组，使得每组和相等，求出满足条件的所有分组中，组内元素和的最小值

输入描述：
第一行输入 m，接着输入m个数，表示此数组，数据范围:1<=M<=50, 1<=nums[i]<=50

输出描述：
最小拆分数组和。

示例：
输入：
7
4 3 2 3 5 2 1
输出：
5
说明：可以等分的情况有：
4 个子集（5），（1,4），（2,3），（2,3）
2 个子集（5, 1, 4），（2,3, 2,3）
但最小的为5
 */
#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------
// 利用回溯的方法，将问题转换成将n个球装到k个桶中，每个球都有k种选择。
// 直接这样写会超时，需要进行剪枝
bool backtrack(vector<int>& nums, int index, vector<int>&bucket, int k, int target){
    // 剪枝1：已经处理完所有的球，由于原先是按照要求装入桶中的，所以这时候肯定是满足条件的
    if(index == nums.size()){
        // 判断每个桶中的球是否满足条件（桶内之和相等）
//        for (int i = 0; i < k; ++i) {
//            if(bucket[i] != target) return false;
//        }
        return true;
    }

    for (int i = 0; i < k; ++i) {
        // 剪枝2：如果与上一个桶内的元素相等，那么，选择上一个桶或者当前桶的结果是一样的
        if(i > 0 && bucket[i] == bucket[i - 1])continue;
        if (bucket[i] + nums[index] > target) continue;

        bucket[i] += nums[index];   // 选择
        if(backtrack(nums, index + 1, bucket, k, target)) return true;
        bucket[i] -= nums[index];   // 撤销选择
    }
    return false;
}


bool canPartition2(vector<int>& nums, int k, int sum){
    if(sum % k != 0) return false;
    int target = sum / k;
    vector<int>bucket(k + 1);

}
// -------------------------------------------------------


// 使用动态规划的方法，将数组的使用情况用二进制数字表示，每一个位表示当前位置元素的情况
// 这里的求余剪枝怎么做到的还没有弄清楚
bool canPartition(vector<int>& nums, int k, int all){
//    int all = accumulate(nums.begin(), nums.end(), 0);  // 最后参数：初始值
    if(all % k != 0) return false;  // 不能被整除
    int per = all / k;  // 每一组应该和的值
    sort(nums.begin(), nums.end());
    if (nums.back() > per) return false;  // 最大值大于每组得值（不可再分）

    int n = nums.size();
    vector<bool>dp(1 << n, false);
    vector<int>curSum(1 << n, 0);
    dp[0] = true;
    for (int i = 0; i < dp.size(); ++i) {
        if(!dp[i]) continue;
        for (int j = 0; j < nums.size(); ++j) {
            if(curSum[i] + nums[j] > per) break;  // 选择全部数字取模后小于等于per，说明选择该数字后的状态再继续往下添加数字是可能能满足题意的
            if (((i >> j) & 1) == 0){  // 当前元素未被使用
                int next = i | (1 << j);  // 使用当前值，并做好标记（标记成1）
                if(!dp[next]){  // 未标记（由上面的条件判断得知，这种组合是可行的，所以修改）
                    curSum[next] = (curSum[i] + nums[j]) % per;  // 取模，如果小于cur，说明之后的组合不可能
                    dp[next] = true;
                }
            }
        }
    }
    return dp[(1 << n) - 1];
}

int main(){
    int m;
    cin >> m;
    vector<int>nums(m);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    for (int i = m; i > 0; i--) {
        if(canPartition(nums, i, sum)){
            cout << sum / i << endl;
            break;
        }
    }
    return 0;
}