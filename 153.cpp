#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// 因为窗口在向后滑动，所以后面的优先级较高，可以用单调队列来做
// 不要总想着用优先队列，也许还有更好的方法

const int N = 1e6 + 5;

int n, k, a[N];

signed main() 
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    deque<int> q;
    
    // min
    for(int i = 1; i <= n; ++i) {
        while(!q.empty() && a[i] < a[q.back()]) q.pop_back();
        q.push_back(i);
        while(!q.empty() && q.front() <= i - k) q.pop_front();
        if(i >= k) cout << a[q.front()] << " ";
    }
    cout << endl;
    
    // max
    q.clear();
    for(int i = 1; i <= n; ++i) {
        while(!q.empty() && a[i] > a[q.back()]) q.pop_back();
        q.push_back(i);
        while(!q.empty() && q.front() <= i - k) q.pop_front();
        if(i >= k) cout << a[q.front()] << " ";
    }
    cout << endl;
}