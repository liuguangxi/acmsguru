#include <bits/stdc++.h>
using namespace std;


using ll = long long;
const int MaxN = 65540;
int N;
int A[MaxN], B[MaxN], C[MaxN];


void add(int pos, int val)
{
    for (; pos <= N; pos += pos & -pos) C[pos] += val;
}


ll get(int pos)
{
    int sum = 0;
    for (; pos; pos -= pos & -pos) sum += C[pos];
    return sum;
}


void solve()
{
    sort(B, B + N);
    int len = unique(B, B + N) - B;
    for (int i = 0; i < N; i++)
        A[i] = lower_bound(B, B + len, A[i]) - B + 1;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += i - get(A[i]);
        add(A[i], 1);
    }
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int d;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d;
        A[i] = B[i] = d;
    }
    solve();
    return 0;
}
