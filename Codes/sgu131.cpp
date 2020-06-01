#include <bits/stdc++.h>
using namespace std;


using ll = long long;
int M, N;
ll f[2][1024];


/*
[0]    [1]    [2]    [3]    [4]    [5]
O O    O O    O        O     O     O +
+        +    O +    O +     +
*/
void solve()
{
    int NS = (1 << (M + 1));
    f[0][NS - 1] = 1;
    int cur = 0, pre;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pre = cur;
            cur ^= 1;
            memset(f[cur], 0, sizeof(f[cur]));
            for (int s = 0; s < NS; s++) {
                if ((s >> M) & 1) {
                    f[cur][(s << 1) ^ NS] += f[pre][s];    // no place
                    if (j > 0 && !(s & 1))
                        f[cur][((s << 1) | 3) ^ NS] += f[pre][s];    // place [5]
                    if (!((s >> (M - 1)) & 1)) {
                        f[cur][((s << 1) | 1 | (1 << M)) ^ NS] += f[pre][s];    // place [4]
                        if (j < M - 1 && !((s >> (M - 2)) & 1))
                            f[cur][((s << 1) | 1 | (1 << (M - 1)) | (1 << M)) ^ NS] += f[pre][s];    // place [0]
                        if (j > 0 && !(s & 1))
                            f[cur][((s << 1) | 3 | (1 << M)) ^ NS] += f[pre][s];    // place [3]
                    }
                } else {
                    if (j > 0 && !((s >> (M - 1)) & 1))
                        f[cur][(s << 1) | 1 | (1 << M)] += f[pre][s];    // place [1]
                    if (j > 0 && !(s & 1))
                        f[cur][(s << 1) | 3] += f[pre][s];    // place [2]
                }
            }
        }
    }
    cout << f[cur][NS - 1] << endl;
}


int main()
{
    cin >> M >> N;
    solve();
    return 0;
}
