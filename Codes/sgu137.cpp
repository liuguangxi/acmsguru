#include <bits/stdc++.h>
using namespace std;


int N, K;


vector<int> f(int n, int k)
{
    int r = k % n;
    if (r == 0) {
        return {k};
    } else {
        vector<int> v0 = f(r, n);
        reverse(v0.begin(), v0.end());
        vector<int> v1;
        int x = k / n;
        for (int c : v0) {
            for (int i = 1; i < c; i++) v1.push_back(x);
            v1.push_back(x + 1);
        }
        return v1;
    }
}


void solve()
{
    vector<int> v = f(N, K);
    for (int x : v) cout << x << " ";
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> K;
    solve();
    return 0;
}
