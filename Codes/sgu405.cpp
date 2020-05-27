#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M, a, b, ai, bi;
    cin >> N >> M;
    vector<int> score(N);
    for (int k = 0; k < M; k++) {
        cin >> a >> b;
        for (int i = 0; i < N; i++) {
            cin >> ai >> bi;
            if ((a < b && ai < bi) || (a == b && ai == bi) || (a > b && ai > bi)) score[i] += 2;
            if (a - b == ai - bi) score[i] += 3;
            if (a == ai) score[i]++;
            if (b == bi) score[i]++;
        }
    }
    for (int x : score) cout << x << " ";
    cout << endl;
    return 0;
}
