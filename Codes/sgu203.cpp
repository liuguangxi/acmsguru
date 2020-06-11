#include <bits/stdc++.h>
using namespace std;


using ll = long long;
int N;


void solve()
{
    ll pi;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll s = 0;
    for (int i = 0; i < N; i++) {
        cin >> pi;
        q.push(pi);
    }
    while (q.size() > 1) {
        ll x = q.top();
        q.pop();
        x += q.top();
        q.pop();
        s += x;
        q.push(x);
    }
    cout << s << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    solve();
    return 0;
}
