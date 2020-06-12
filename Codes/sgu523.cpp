#include <bits/stdc++.h>
using namespace std;


const int MaxN = 101;
int N, F;
int E[MaxN];


void solve()
{
    vector<bool> on(MaxN);
    int f1= F;
    for (int i = 0; i < N; i++) {
        cin >> E[i];
        on[E[i]] = true;
    }
    for (int i = 0; i < N; i++) {
        int f2 = E[i];
        if (on[f2]) {
            if (f2 > f1) {
                for (int k = f1; k <= f2; k++) {
                    if (on[k]) cout << k << " ";
                    on[k] = false;
                }
            } else {
                for (int k = f1; k >= f2; k--) {
                    if (on[k]) cout << k << " ";
                    on[k] = false;
                }
            }
            f1 = f2;
        }
    }
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> F;
    solve();
    return 0;
}
