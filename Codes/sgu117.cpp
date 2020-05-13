#include <bits/stdc++.h>
using namespace std;


int powmod(int a, int b, int m)
{
    int c = 1;
    for (; b; b >>= 1, a = a * a % m) {
        if (b & 1)
            c = c * a % m;
    }
    return c;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M, K;
    int x;
    int ans = 0;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (powmod(x, M, K) == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
