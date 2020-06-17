#include <bits/stdc++.h>
using namespace std;


const int MaxN = 10;
int N, K;
int S;
bool col[MaxN], diag1[2 * MaxN], diag2[2 * MaxN];


void dfs(int row, int num)
{
    int xmin = (N - row == K - num) ? 0 : -1;
    for (int x = xmin; x < N; x++) {
        if (x == -1) {
            dfs(row + 1, num);
        } else if (!col[x] && !diag1[row + x] && !diag2[row - x + N]) {
            if (num + 1 == K) {
                S++;
            } else {
                col[x] = diag1[row + x] = diag2[row - x + N] = true;
                dfs(row + 1, num + 1);
                col[x] = diag1[row + x] = diag2[row - x + N] = false;
            }
        }
    }
}


void solve()
{
    if (K == 0) S = 1;
    else if (K <= N) dfs(0, 0);
    cout << S << endl;
}


int main()
{
    cin >> N >> K;
    solve();
    return 0;
}
