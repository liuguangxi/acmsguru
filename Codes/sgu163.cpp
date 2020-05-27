#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N, e, m;
    int ans = 0;
    cin >> N >> e;
    for (int i = 0; i < N; i++) {
        cin >> m;
        int t = m;
        for (int j = 2; j <= e; j++) t *= m;
        if (t > 0) ans += t;
    }
    cout << ans << endl;
    return 0;
}
