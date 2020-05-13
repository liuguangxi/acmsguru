#include <bits/stdc++.h>
using namespace std;


int main()
{
    int P, M, C, K, R, V;
    cin >> P >> M >> C >> K >> R >> V;
    int ans = min({P/K, M/R, C/V});
    cout << ans << endl;
    return 0;
}
