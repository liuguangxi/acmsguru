#include <bits/stdc++.h>
using namespace std;


int N;


void solve()
{
    const int Inf = 0x7fffffff;
    vector<pair<pair<int, int>, int>> a(N);
    vector<int> f(N, Inf);
    vector<int> idxlast(N, -1);
    vector<int> idxpre(N, -1);
    int len = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end(),
        [] (const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2) {
            return (p1.first.first < p2.first.first) ||
            (p1.first.first == p2.first.first && p1.first.second > p2.first.second);
        }
    );

    for (int i = 0; i < N; i++) {
        int x = a[i].first.second;
        int k = lower_bound(f.begin(), f.end(), x) - f.begin();
        f[k] = x;
        idxlast[k] = i;
        if (k > 0) idxpre[i] = idxlast[k - 1];
        len = max(len, k + 1);
    }

    cout << len << endl;
    int t = idxlast[len - 1];
    while (t != -1) {
        cout << a[t].second << " ";
        t = idxpre[t];
    }
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    solve();
    return 0;
}
