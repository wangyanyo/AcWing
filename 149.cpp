#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define LL long long

// 思路就是哈夫曼树，哈夫曼树本就是一种贪心，要理解哈夫曼树的本质，并将这道题套到哈夫曼树上
// 类似套公式，但你必须理解公式的原理

struct Node{
    LL val;
    int dep;
};

int n, k;
priority_queue<Node> q;

bool operator<(Node a, Node b) {
    if(a.val != b.val) return a.val > b.val;
    else return a.dep > b.dep;
}

void solve()
{
    while((n - 1) % (k - 1)) {
        q.push(Node{0ll, 0});
        n++;
    }
    
    LL ans = 0;
    while(q.size() > 1) {
        LL sum = 0;
        int dep = 0;
        for(int i = 1; i <= k; ++i) {
            sum += q.top().val;
            dep = max(dep, q.top().dep);
            q.pop();
        }
        
        ans += sum;
        q.push(Node{sum, dep + 1});
    }
    
    cout << ans << endl;
    cout << q.top().dep << endl;
}

signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        LL w;
        cin >> w;
        q.push(Node{w, 0});
    }
    
    solve();
    
    return 0;
}
