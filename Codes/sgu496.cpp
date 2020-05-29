#include <bits/stdc++.h>
using namespace std;


const int MaxN = 5000;
int N;
int X1[MaxN], Y1[MaxN], X2[MaxN], Y2[MaxN];


void solve()
{
    int s = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((X1[i] == X1[j] && Y1[i] == Y1[j]) || (X1[i] == X2[j] && Y1[i] == Y2[j]) ||
                (X2[i] == X1[j] && Y2[i] == Y1[j]) || (X2[i] == X2[j] && Y2[i] == Y2[j])) {
                if ((X2[i] - X1[i]) * (X2[j] - X1[j]) + (Y2[i] - Y1[i]) * (Y2[j] - Y1[j]) == 0)
                    s++;
            }
        }
    }
    cout << s << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    solve();
    return 0;
}
