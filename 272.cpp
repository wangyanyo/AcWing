#include<iostream>
#include<algorithm>
using namespace std;
const int N = 3005;

int n, a[N], b[N], dp[N][N], s[N], cnt;
signed main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        int res = 1;
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], res);
            else if(a[i] > b[j]) res = max(res, dp[i - 1][j] + 1);
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}
