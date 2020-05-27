#include <bits/stdc++.h>
using namespace std;


const int MaxL = 1010;
int N, M;
char G[MaxL][MaxL];


void dfs(int x, int y)
{
    const static int Dx[4] = {0, -1, 0, 1};
    const static int Dy[4] = {1, 0, -1, 0};
    int num = 0;
    for (int d = 0; d < 4; d++) {
        int xd = x + Dx[d];
        int yd = y + Dy[d];
        if (xd >= 0 && xd < N && yd >= 0 && yd < M && G[xd][yd] == 'X')
            num++;
    }
    if (num >= 2) {
        G[x][y] = 'X';
        for (int d = 0; d < 4; d++) {
            int xd = x + Dx[d];
            int yd = y + Dy[d];
            if (xd >= 0 && xd < N && yd >= 0 && yd < M && G[xd][yd] == '.')
                dfs(xd, yd);
        }
    }
}


void solve()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (G[i][j] == '.') dfs(i, j);
    }
    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (G[i][j] == 'X') s++;
    }
    cout << s << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> G[i];
    solve();
    return 0;
}
