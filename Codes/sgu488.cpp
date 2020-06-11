#include <bits/stdc++.h>
using namespace std;


const int MaxN = 1000000;
int N;
int A[MaxN];


void solve()
{
    int hmax = 0, dmax = 0;
    int hl = 0, hr = 0;
    int dl = 0, dr = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] == A[i - 1]) {
            hl = hr = dl = dr = 0;
        } else if (A[i] > A[i - 1]) {
            hl = (hr > 0) ? 1 : hl + 1;
            hr = 0;
            if (dl > 0) {
                dr++;
                dmax = max(dmax, min(dl, dr));
            }
        } else {
            if (hl > 0) {
                hr++;
                hmax = max(hmax, min(hl, hr));
            }
            dl = (dr > 0) ? 1 : dl + 1;
            dr = 0;
        }
    }
    cout << hmax << " " << dmax << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> A[i];
        solve();
    }
    return 0;
}
