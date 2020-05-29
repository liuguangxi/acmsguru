#include <bits/stdc++.h>
using namespace std;


const int MaxL = 1000;
int N, M;
short A[MaxL][MaxL];


void solve()
{
    for (int j = M - 1; j >= 0; j--) {
        for (int i = N - 1; i >= 0; i--) {
            if (i < N - 1) A[i][j] = min(A[i][j], A[i + 1][j]);
            if (j < M - 1) A[i][j] = min(A[i][j], A[max(0, i - 1)][j + 1]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cout << A[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }
    solve();
    return 0;
}
