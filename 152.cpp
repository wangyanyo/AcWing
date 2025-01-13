#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 这个问题的关键点就是控制变量，如果控制矩形的底边，那么这就是一个"直方形中的最大矩形"的问题
// “直方形中的最大矩形”的关键点也是限制，如果限制矩形的高度为当前直方图的高度，接下来的工作就是找左右边界
// 通过单调栈，把高于自己的直方图都出栈，这样就找到了左边界，自己被出栈时，肯定是右边第一个小于自己的，就是右边界

const int N = 1005;

int n, m, ans;
int a[N][N];

void solve(int s[N])
{
    stack<int> sk;
    sk.push(0);
    for(int i = 1; i <= m; ++i) {
        while(sk.size() > 1 && s[i] < s[sk.top()]) {
            int k = s[sk.top()];
            sk.pop();
            int res = k * (i - sk.top() - 1);
            ans = max(ans, res);
        }
        if(s[i] > s[sk.top()]) sk.push(i);
    }

    while(sk.size() > 1) {
        int k = s[sk.top()];
        sk.pop();
        int res = k * ((m + 1) - sk.top() - 1);
        ans = max(ans, res);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if(c == 'R') a[i][j] = 0;
            else a[i][j] = a[i - 1][j] + 1;
        }
        solve(a[i]);
    }
    cout << ans << endl;
    
    return 0;
}