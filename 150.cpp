#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 1e5 + 5;

char s[N];

bool check(char x, char y)
{
    return (x == '(' && y == ')') ||
        (x == '[' && y == ']') ||
        (x == '{' && y == '}');
}

int solve()
{
    stack<int> sk;
    sk.push(0);

    int res = 0;
    for(int i = 1; s[i]; ++i) {
        if(check(s[sk.top()], s[i])) {
            sk.pop();
            res = max(res, i - sk.top());
        }
        else {
            sk.push(i);
        }
    }

    return res;
}

signed main()
{
    cin >> s + 1;
    cout << solve() << endl;
    return 0;
}