#include <bits/stdc++.h>
using namespace std;


const int MaxL = 110;
int N, M;
char G[MaxL][MaxL];


int solve()
{
    int x = -1, y = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (G[i][j] == 'P') {
                x = j;
                y = i;
            }
        }
    }
    y++;
    while (y < N) {
        if (G[y][x] == '.') {
            y++;
        } else if (G[y][x] == '/') {
            if (x == 0) return -1;
            x--;
            if (G[y][x] == '\\') return -1;
            else if (G[y][x] == '/') y++;
        } else {
            if (x == M - 1) return -1;
            x++;
            if (G[y][x] == '/') return -1;
            else if (G[y][x] == '\\') y++;
        }
    }
    return x + 1;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> G[i];
    cout << solve() << endl;;
    return 0;
}
