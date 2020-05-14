#include <bits/stdc++.h>
using namespace std;


const int MaxN = 10000+10;
int N;
int A[MaxN];


void solve()
{
    int sa = 0;
    for (int i = 0; i < N; i++)
        sa += A[i];
    if (sa == 0) {
        cout << "No solution" << endl;
        return;
    }

    vector<int> p(N);
    vector<bool> v(N);
    int s0 = 0;
    for (int i = 0; i < N; i++) {
        int t = A[i] * 100;
        p[i] = t / sa;
        s0 += p[i];
        if (t % sa != 0)
            v[i] = true;
    }
    s0 = 100 - s0;
    for (int i = 0; i < N; i++) {
        if (s0 == 0) {
            break;
        } else if (v[i]) {
            p[i]++;
            s0--;
        }
    }

    for (int x : p) cout << x << " ";
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    solve();
    return 0;
}
