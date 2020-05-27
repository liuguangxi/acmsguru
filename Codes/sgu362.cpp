#include <bits/stdc++.h>
using namespace std;


const int L = 20;
int G[L][L];


void solve(int n, int m, int is, int js)
{
    const int DirI[4] = {1, 0, -1, 0};
    const int DirJ[4] = {0, -1, 0, 1};
    const char Move[4] = {'D', 'L', 'U', 'R'};

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            G[i][j] = 1;

    while (1) {
        bool ok = false;
        for (int d = 0; d < 4; d++) {
            if (G[is + DirI[d]][js + DirJ[d]] == 1) {
                ok = true;
                G[is][js] = 0;
                is += DirI[d];
                js += DirJ[d];
                cout << Move[d];
                break;
            }
        }
        if (!ok) break;
    }
    cout << endl;
}


int main()
{
    int N, M, Is, Js;
    cin >> N >> M;
    cin >> Is >> Js;
    solve(N, M, Is, Js);
    return 0;
}
