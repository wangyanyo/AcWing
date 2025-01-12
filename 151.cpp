#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

// 对括号理解的没问题，对后序表达式理解也没问题，但是对负数理解有问题
// 通过加入特殊符号解决了负数的问题

const int N = 1e5 + 5;

int n;
char s[N];
stack<int> sk1;
stack<char> sk2;

int val(char c) 
{
    if(c == '(') return 0;
    if(c == ')') return 1;
    if(c == '+') return 2;
    if(c == '-') return 3;
    if(c == '*') return 4;
    if(c == '/') return 5;
    if(c == '^') return 6;
    if(c == 's') return 7;
}

bool check(char x, char y)
{
    return val(x) < val(y);
}

int power(int x, int y) 
{
    int res = 1;
    while(y--) res *= x;
    return res;
}

void calc(char c)
{
    int t2 = sk1.top(); sk1.pop();
    int t1 = sk1.top(); sk1.pop();
    
    int res;
    if(c == '+') res = t1 + t2;
    if(c == '-') res = t1 - t2;
    if(c == '*') res = t1 * t2;
    if(c == '/') res = t1 / t2;
    if(c == '^') res = power(t1, t2);
    if(c == 's') res = t1 - t2;
    
    sk1.push(res);
}

void work1(char x)
{
    if(x == '(') sk2.push(x);
    else if(x == ')') {
        while(!sk2.empty()) {
            char c = sk2.top();
            sk2.pop();
            if(c == '(') break;
            calc(c);
        }
    }
    else {
        while(!sk2.empty() && check(x, sk2.top())) {
            char c = sk2.top();
            sk2.pop();
            calc(c);
        }
        sk2.push(x);
    }
}

void work2(int x)
{
    sk1.push(x);
}

int solve()
{
    for(int i = 1, j = 1; i <= n; i = j) {
        while(i <= n && s[i] == ' ') i++;
        if(i > n) break;

        if(s[i] == '-' && s[i - 1] != ')' && (s[i - 1] < '0' || s[i - 1] > '9') && (s[i + 1] >= '0' && s[i + 1] <= '9' || s[i + 1] == '(')) {
            work2(0);
            work1('s');
            j = i + 1;
            continue;
        }

        if(s[i] < '0' || s[i] > '9') {
            work1(s[i]);
            j = i + 1;
            continue;
        }
        
        for(j = i; j <= n; ++j) {
            if(s[j] < '0' || s[j] > '9') break;
        }
        
        int res = 0;
        for(int t = i; t < j; ++t) {
            res = res * 10 + s[t] - '0';
        }

        work2(res);
    }
    
    while(!sk2.empty()) {
        char c = sk2.top();
        sk2.pop();
        if(c == '(' || c == ')') continue;
        calc(c);
    }
    
    return sk1.top();
}

signed main()
{
    cin >> s + 1;
    n = strlen(s + 1);
    cout << solve() << endl;
    return 0;
}