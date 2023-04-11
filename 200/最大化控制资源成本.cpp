/**
 * 题目描述
公司创新实验室正在研究如何最小化资源成本，最大化资源利用率，请你设计算法帮他们解决一个任务混部问题：
有taskNum项任务，每个任务有开始时间（startTime），结束时间（endTime），并行度（parallelism）三个属性，
并行度是指这个任务运行时将会占用的服务器数量，一个服务器在每个时刻可以被任意任务使用但最多被一个任务占用，任务运行完成立即释放（结束时刻不占用）。
任务混部问题是指给定一批任务，让这批任务由同一批服务器承载运行，

请你计算完成这批任务混部最少需要多少服务器，从而最大化控制资源成本。

 输出描述：
     一个整数，表示最少需要的服务器数量
     示例1：
         2
         2 3 1
         6 9 2
         0 5 1
     输出
         2

说明
    共有三个任务，第一个任务在时间区间[2，3] 运行，占用1个服务器，第二个任务在时间区间[6，9] 运行，
    占用2个服务器，第三个任务在时间区间(0，5] 运行，占用1个服务器，需要最多服务器的时间区间为(2，3] 和(6，9]，
    需要2个服务器示例2 输入输出示例仅供调试，后台判断数据一般不包含示例
    输入
        2
        3 9 2
        4 7 3
    输出
        5
说明
共两个任务，第一个任务在时间区间(3，9] 运行，占用2个服务器，第二个任务在时间区间[4，7] 运行，
 占用3个服务器，需要最多服务器的时间区间为[4，7] ，需要5个服务器备注:
    1<=taskNum<=100000
    0<=startTime<endTime<=50000
    1<=parallelism<=100
 */


/** 算法思路
 *  1        5      (服务器=3)
 * +   2           8  (服务器=2)
 * ————————————————
 *  3 5 5 5 5 2 2 2   （大小为8的数组记录每一个时间段中需要的最最少服务器）
 *  res = 上面数组中的最大值
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> tasks;
    int leftBoundary = 0, rightBoundary = 0;

    int start = 0, end = 0, servers = 0;
    for (int i = 0; i < n; ++i) {
        cin >> start >> end >> servers;
        rightBoundary = max(rightBoundary, end);
        tasks.push_back({start, end, servers});
    }

    vector<int>resArray = vector<int>(rightBoundary, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = tasks[i][0]; j < tasks[i][1]; ++j) {
            resArray[j] += tasks[i][2];
        }
    }

    cout << *max_element(resArray.begin(), resArray.end()) << endl;
}



//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<algorithm>
//#include<string.h>
//#include<exception>
//#include<map>
//#include<cmath>
//#include<unordered_map>
//#include<set>
//#include<climits>
//#include<ctype.h>
//#include<queue>
//#include<stack>
//#include<list>
//#include<bitset>
//using namespace std;
//
//vector<int> split(string input_str) {
//    vector<int> v;
//
//    while (input_str.find(",") != string::npos) {
//        int found = input_str.find(",");
//        v.push_back(stoi(input_str.substr(0, found)));
//        input_str = input_str.substr(found + 1);
//    }
//    v.push_back(stoi(input_str));
//    return v;
//}
//
//vector<string> split_str(string params_str, string op) {
//    vector<string> p;
//    while (params_str.find(op) != string::npos) {
//        int found = params_str.find(op);
//        p.push_back(params_str.substr(0, found));
//        params_str = params_str.substr(found + 1);
//    }
//    p.push_back(params_str);
//    return p;
//}
//
//bool comp(vector<int>& a, vector<int>& b) {
//    if (a[0] > b[0]) {
//        return false;
//    } else if (a[0] == b[0]) {
//        if (a[1] > b[1]) {
//            return false;
//        }
//    }
//    return true;
//}
//struct tmp2
//{
//    bool operator() (vector<int> a, vector<int> b)
//    {
//        return a[0] > b[0]; //大顶堆
//    }
//};
//
//int minMeetingRooms(vector<vector<int>> ranges) {
//    priority_queue<vector<int>, vector<vector<int>>, tmp2> pq;
//    sort(ranges.begin(), ranges.end(),
//         [](auto a, auto b) { return  a[0] < b[0]; });
//
//    int res = 0;
//    int temp_res = 0;
//    for (int i = 0; i < ranges.size(); i ++ ) {
//        while (pq.size() > 0) {
//
//            if (pq.top()[0] < ranges[i][0]) {
//                temp_res -= pq.top()[1];
//                pq.pop();
//            } else {
//                break;
//            }
//        }
//
//        pq.push(vector<int> {ranges[i][1], ranges[i][2]});
//        temp_res += ranges[i][2];
//
//        if (temp_res > res) {
//            res = temp_res;
//        }
//    }
//    return res;
//}
//
//
//int main() {
//    // 输入处理
//    int taskNum = 0;
//    cin >> taskNum;
//    vector<vector<int>> ranges;
//    for (int i = 0; i < taskNum; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        //三个元素分别代表，开始时间，结束时间，占用机器个数
//        vector<int> single_range_with_num;
//        single_range_with_num.push_back(a);
//        single_range_with_num.push_back(b);
//        single_range_with_num.push_back(c);
//        ranges.push_back(single_range_with_num);
//    }
//
//    cout << minMeetingRooms(ranges);
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Event {
//    int time;
//    int servers;
//    bool operator<(const Event& other) const {
//        return time < other.time || (time == other.time && servers > other.servers);
//    }
//};
//
//int main() {
//    int taskNum;
//    cin >> taskNum;
//    vector<Event> events;
//    for (int i = 0; i < taskNum; ++i) {
//        int startTime, endTime, parallelism;
//        cin >> startTime >> endTime >> parallelism;
//        events.push_back({startTime, parallelism});
//        events.push_back({endTime, -parallelism});
//    }
//
//    sort(events.begin(), events.end());
//
//    int maxServers = 0, currentServers = 0;
//    for (const auto& event : events) {
//        currentServers += event.servers;
//        maxServers = max(maxServers, currentServers);
//    }
//
//    cout << maxServers << endl;
//
//    return 0;
//}







//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//bool comp(vector<int> a, vector<int> b) {
//    return a[0] < b[0];
//}
//int main() {
//    int task_num;
//    cin >> task_num;
//    vector<vector<int>> ranges;
//    for (int i = 0; i < task_num; i++) {
//        int a, b, c;  // 始末 +　需要的服务器数量
//        cin >> a >> b >> c;
//        ranges.push_back({a, b, c});
//    }
//
//    // 按照起始位置进行排序
//    sort(ranges.begin(), ranges.end(), comp);
//    priority_queue<pair<int, int>> pq;
//    int res = 0, temp_res = 0;
//    for (auto & range : ranges) {
//        while (!pq.empty()) {
//            auto top = pq.top();
//            if (top.first < range[0]) {  // 不重叠
//                pq.pop();
//                temp_res -= top.second;   // 撤销选择，直到重叠
//            } else break;
//        }
//        pq.emplace(range[1], range[2]);  // 结束位置 + 需要的服务器数量
//        temp_res += range[2];
//        if (temp_res > res) {
//            res = temp_res;
//        }
//    }
//    cout << res << endl;
//    return 0;
//}





//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//    int numOfTasks;
//    cin >> numOfTasks;
//
//    vector<vector<int>> requirements(numOfTasks, vector<int>(3, 0));
//    for(int i = 0; i < numOfTasks; ++i){
//        for(int j = 0; j < 3; ++j) cin >> requirements[i][j];
//    }
//
//}
