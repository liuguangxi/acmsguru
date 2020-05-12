#include <bits/stdc++.h>
using namespace std;


int main()
{
    int K;
    cin >> K;
    int ans;
    if (K <= 2) ans = K;
    else {
        int a = 1, b = 1;
        ans = a + b;
        for (int i = 3; i <= K; i++) {
            int c = a + b;
            a = b; b = c;
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}
