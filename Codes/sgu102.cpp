#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;
    int ans = 0;
    for (int x = 1; x <= N; x++) {
        if (__gcd(N, x) == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
