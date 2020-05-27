#include <bits/stdc++.h>
using namespace std;


int N, k1, k2, p1, p2, p3;


int solve()
{
    if (N < p1) return 0;
    int s = k1;
    N -= p1;
    if (N == 0) return s;
    int t = min((N + p2 - 1) / p2, k2);
    s += t;
    N -= t * p2;
    if (N <= 0) return s;
    t = (N + p3 - 1) / p3;
    s += t;
    return s;
}


int main()
{
    cin >> N >> k1 >> k2 >> p1 >> p2 >> p3;
    cout << solve() << endl;
    return 0;
}
