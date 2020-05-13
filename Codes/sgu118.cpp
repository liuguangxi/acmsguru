#include <bits/stdc++.h>
using namespace std;


using ll = long long;
int N;
int A[1000];


void solve()
{
    ll s = 1;
    for (int i = N - 1; i >= 1; i--)
        s = (A[i] * s + 1) % 9;
    s = s * A[0] % 9;
    if (s == 0) s = 9;
    cout << s << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int K;
    cin >> K;
    while (K--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> A[i];
        solve();
    }
    return 0;
}
