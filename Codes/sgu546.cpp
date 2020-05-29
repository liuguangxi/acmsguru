#include <bits/stdc++.h>
using namespace std;


int N, A, B;
string S;


void rpl(int r, char cf, char ct)
{
    for (int i = 0; i < N; i++) {
        if (r > 0 && S[i] == cf) {
            r--;
            S[i] = ct;
        }
    }
}


void solve()
{
    if (A + B > N) {
        cout << -1 << endl;
        return;
    }

    int c0 = count(S.begin(), S.end(), '0');
    int c1 = count(S.begin(), S.end(), '1');
    int t;
    if (c0 <= A) {
        if (c1 <= B) {
            t = A - c0 + B - c1;
            rpl(A - c0, '2', '0');
            rpl(B - c1, '2', '1');
        } else {
            t = max(A - c0, c1 - B);
            if (A - c0 <= c1 - B) {
                rpl(A - c0, '1', '0');
                rpl(c1 - B - A + c0, '1', '2');
            } else {
                rpl(c1 - B, '1', '0');
                rpl(A - c0 - c1 + B, '2', '0');
            }
        }
    } else {
        if (c1 < B) {
            t = max(c0 - A, B - c1);
            if (c0 - A >= B - c1) {
                rpl(B - c1, '0', '1');
                rpl(c0 - A - B + c1, '0', '2');
            } else {
                rpl(c0 - A, '0', '1');
                rpl(B - c1 - c0 + A, '2', '1');
            }
        } else {
            t = c0 - A + c1 - B;
            rpl(c0 - A, '0', '2');
            rpl(c1 - B, '1', '2');
        }
    }
    cout << t << "\n" << S << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> A >> B >> S;
    solve();
    return 0;
}
