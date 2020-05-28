#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int maxb = -1, s = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].second < maxb)
            s++;
        else
            maxb = v[i].second;
    }
    cout << s << endl;
    return 0;
}
