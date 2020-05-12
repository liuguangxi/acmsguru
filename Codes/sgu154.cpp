#include <bits/stdc++.h>
using namespace std;


int numzero(int n)
{
    int s = 0;
    n /= 5;
    while (n > 0) {
        s += n;
        n /= 5;
    }
    return s;
}


void solve(int q)
{
    int lo = 1, hi = 1000000000, mid;
    int num;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        num = numzero(mid);
        if (num < q)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (numzero(lo) != q)
        cout << "No solution" << endl;
    else
        cout << lo << endl;
}


int main()
{
    int Q;
    cin >> Q;
    solve(Q);
    return 0;
}
