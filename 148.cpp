// nice <nice> ./148.o  这是设置普通任务的优先级
// renice <nice> -p <pid> 这是修改普通任务进程的优先级
// chrt -f <优先级> -p <pid> 这是将普通任务转为实时任务

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e4 + 5;

int n, a[N];
signed main() {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        q.push(a[i]);
    }
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        int t1 = q.top(); q.pop();
        int t2 = q.top(); q.pop();
        ans += t1 + t2;
        q.push(t1 + t2);
    }
    cout << ans << endl;
}
