#include <bits/stdc++.h>
using namespace std;


int solve(int l, int r, int q)
{
    if (l == r) return 1;
    int n = abs(l - r) + 1;
    int k = n / 2;
    if (l < r) {
        if (q <= l + k - 1)
            return n - k + solve(l + k - 1, l, q);
        else
            return solve(r, l + k, q);
    } else {
        if (q >= l - k + 1)
            return n - k + solve(l - k + 1, l, q);
        else
            return solve(r, l - k, q);
    }
}


int main()
{
    int N, Q;
    cin >> N >> Q;
    cout << solve(1, N, Q) << endl;
    return 0;
}
