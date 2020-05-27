#include <bits/stdc++.h>
using namespace std;


const int MaxN = 100;
int N;
int T[MaxN];
int L[MaxN];


void solve()
{
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) v.emplace_back(L[i], T[i]);
    sort(v.begin(), v.end(),
        [] (const pair<int, int> & p1, const pair<int, int> & p2)
        {return p1.first > p2.first;}
    );
    int s = 0, t = 0;
    for (const auto &x : v) {
        t += x.second;
        s = max(s, t + x.first);
    }
    cout << s << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> T[i];
    for (int i = 0; i < N; i++) cin >> L[i];
    solve();
    return 0;
}
