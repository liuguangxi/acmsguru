#include <bits/stdc++.h>
using namespace std;


int x, y;


bool only25(int n)
{
    while (n % 2 == 0) n /= 2;
    while (n % 5 == 0) n /= 5;
    return n == 1;
}


inline int f(int a)
{
    return a * 10 % y;
}


void solve()
{
    x %= y;
    if (x == 0) {
        cout << "0 0" << endl;
    } else if (only25(y)) {
        int i = 0;
        do {
            x = f(x);
            i++;
        } while (x != 0);
        cout << i << " 0" << endl;
    } else {
        int x1, x2, i, p;
        x1 = x2 = x;
        i = 0;
        do {
            x1 = f(x1);
            x2 = f(f(x2));
            i++;
        } while (x1 != x2);
        x1 = x;
        i = 0;
        while (x1 != x2) {
            x1 = f(x1);
            x2 = f(x2);
            i++;
        }
        p = 0;
        do {
            x2 = f(x2);
            p++;
        } while (x1 != x2);
        cout << i << " " << p << endl;
    }
}


int main()
{
    cin >> x >> y;
    solve();
    return 0;
}
