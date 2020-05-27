#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxK = 60;
ll p[MaxK + 1];


void ins(ll x)
{
    for (int i = MaxK; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (p[i] == 0) {
                p[i] = x;
                break;
            } else {
                x ^= p[i];
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    ll ai;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ai;
        ins(ai);
    }
    ll ans = 0;
    for (int i = MaxK; i >= 0; i--) ans = max(ans, ans ^ p[i]);
    cout << ans << endl;
    return 0;
}
