#include <bits/stdc++.h>
using namespace std;


int N, M;


void solve()
{
    vector<int> hit(N + 1, 100);
    vector<int> score(N + 1, 0);
    int n1, n2;
    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        if (hit[n2] > 0) score[n1] += 3;
        hit[n2] -= 8;
    }
    for (int i = 1; i <= N; i++) {
        cout << hit[i] << " ";
        if (hit[i] > 0) score[i] += hit[i] / 2;
        cout << score[i] << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    solve();
    return 0;
}
