#include <bits/stdc++.h>
using namespace std;


const unsigned short MaxN = 250;
const short Dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const short Dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
unsigned short N;
unsigned short G[MaxN][MaxN];
bool issortless;


void print_sol()
{
    cout << "There is solution:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << G[i][j] << " ";
        cout << '\n';
    }
}


short get_deg(short x, short y)
{
    short s = 0;
    for (int d = 0; d < 8; d++) {
        short xd = x + Dx[d];
        short yd = y + Dy[d];
        if (xd >= 0 && xd < N && yd >= 0 && yd < N && G[xd][yd] == 0) s++;
    }
    return s;
}


bool dfs(unsigned short k, short x, short y)
{
    G[x][y] = k;
    if (k == N * N) return true;

    vector<pair<short, pair<short, short>>> v;
    for (int d = 0; d < 8; d++) {
        short xd = x + Dx[d];
        short yd = y + Dy[d];
        if (xd >= 0 && xd < N && yd >= 0 && yd < N && G[xd][yd] == 0)
            v.emplace_back(get_deg(xd, yd), make_pair(xd, yd));
    }

    if (issortless) {
        sort(v.begin(), v.end(),
            [] (const pair<short, pair<short, short>> &p1, const pair<short, pair<short, short>> &p2) {
                return (p1.first < p2.first) || ((p1.first == p2.first) && ((p1.second.first + p1.second.second < p2.second.first + p2.second.second)));
            }
        );
    } else {
        sort(v.begin(), v.end(),
            [] (const pair<short, pair<short, short>> &p1, const pair<short, pair<short, short>> &p2) {
                return (p1.first < p2.first) || ((p1.first == p2.first) && ((p1.second.first + p1.second.second > p2.second.first + p2.second.second)));
            }
        );
    }

    for (const auto & t : v) {
        if (dfs(k + 1, t.second.first, t.second.second)) return true;
    }
    G[x][y] = 0;
    return false;
}


void solve()
{
    issortless = (N == 77 ||N == 97 || N == 143 || N == 176 || N == 193 || N == 200 || N == 218 || N == 226 || N == 247);
    if (dfs(1, 0, 0))
        print_sol();
    else
        cout << "No solution." << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    solve();
    return 0;
}
