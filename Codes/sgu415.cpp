#include <bits/stdc++.h>
using namespace std;


const int MaxN = 200+5;
const int MaxX = 10000+5;
int N, X;
int A[MaxN];
bool vl[MaxN][MaxX];
bool vr[MaxN][MaxX];


void solve()
{
    vl[0][0] = vr[N + 1][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= X; j++) vl[i][j] = vl[i - 1][j];
        int ai = A[i];
        for (int j = X; j >= ai; j--) vl[i][j] = vl[i][j] || vl[i][j - ai];
    }
    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= X; j++) vr[i][j] = vr[i + 1][j];
        int ai = A[i];
        for (int j = X; j >= ai; j--) vr[i][j] = vr[i][j] || vr[i][j - ai];
    }

    vector<int> num;
    for (int i = 1; i <= N; i++) {
        bool flag = false;
        for (int j = 0; j <= X; j++) {
            if (vl[i - 1][j] && vr[i + 1][X - j]) {
                flag = true;
                break;
            }
        }
        if (!flag) num.push_back(A[i]);
    }
    cout << num.size() << endl;
    if (num.size() > 0) {
        for (int x : num) cout << x << " ";
        cout << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> X;
    for (int i = 1; i <= N; i++) cin >> A[i];
    solve();
    return 0;
}
