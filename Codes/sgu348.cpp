#include <bits/stdc++.h>
using namespace std;


using ll = long long;


ll solve(ll n)
{
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 2);
        n /= 2;
    }
    reverse(v.begin(), v.end());

    int lenv = v.size();
    bool flag;
    while (1) {
        flag = false;
        ll x = 0;
        for (int i = 0; i < lenv; i++) x = x * 2 + v[i];
        for (int i = 1; i < lenv; i++) {
            if (v[i] == 1) {
                ll xi = 0;
                for (int j = 0; j < lenv; j++) xi = xi * 2 + v[(j + i) % lenv];
                if (xi < x) {
                    v[i] = 0;
                    for (int j = i + 1; j < lenv; j++) v[j] = 1;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) return x;
    }
}


int main()
{
    ll N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}
