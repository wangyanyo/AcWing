#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
// 加入了一个反悔的选项，每次取堆顶都是做一次选择(包括反悔选择)，每次选择都是最优的

struct List {
    int val, nxt, pre, flag;
}s[N];

struct Node {
    int val, p;
};

int n, k, a[N];

bool operator<(Node a, Node b) {
    return a.val > b.val;
}

int solve()
{
    priority_queue<Node> q;
    s[0].val = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++i) {
        s[i].val = a[i];
        s[i].pre = i - 1;
        s[i].nxt = i < n ? i + 1 : 0;
        q.push(Node{a[i], i});
    }

    int res = 0;
    while(k) {
        Node t = q.top(); q.pop();
        if(s[t.p].flag) continue;
        int p = t.p, val = t.val;
        k--;
        
        res += t.val;
        s[s[p].pre].flag = 1;
        s[s[p].nxt].flag = 1;
        s[p].val = s[s[p].pre].val + s[s[p].nxt].val - s[p].val;
        q.push(Node{s[p].val, p});
        s[p].pre = s[s[p].pre].pre;
        s[p].nxt = s[s[p].nxt].nxt;
        s[s[p].pre].nxt = p;
        s[s[p].nxt].pre = p;
    }

    return res;
}

signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    n -= 1;
    for(int i = 1; i <= n; ++i) { 
        a[i] = a[i + 1] - a[i];
    }

    cout << solve() << endl;

    return 0;
}