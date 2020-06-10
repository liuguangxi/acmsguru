#include <bits/stdc++.h>
using namespace std;


const int MaxL = 110;
int N, M;
char G[MaxL][MaxL];
bool passed[MaxL][MaxL];
string path;


void solve()
{
    const static int Dx[4] = {1, 0, -1, 0};
    const static int Dy[4] = {0, 1, 0, -1};
    int x = 0, y = 0, d = 0;
    int s = 0;
    for (char c : path) {
        if (c == 'L') d = (d + 3) % 4;
        else if (c == 'R') d = (d + 1) % 4;
        else {
            x += Dx[d];
            y += Dy[d];
            int x1 = (d == 2) ? x : x - 1;
            int y1 = (d == 3) ? y : y - 1;
            int x2 = (d == 0) ? x - 1 : x;
            int y2 = (d == 1) ? y - 1 : y;
            if (x1 >= 0 && x1 < M && y1 >= 0 && y1 < N) {
                int t = G[y1][x1] - '0';
                s += (passed[y1][x1]) ? t / 2 : t;
                passed[y1][x1] = true;
            }
            if (x2 >= 0 && x2 < M && y2 >= 0 && y2 < N) {
                int t = G[y2][x2] - '0';
                s += (passed[y2][x2]) ? t / 2 : t;
                passed[y2][x2] = true;
            }
        }
    }
    cout << s << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> G[i];
    cin >> path;
    solve();
    return 0;
}
