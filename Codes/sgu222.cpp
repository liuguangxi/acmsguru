#include <bits/stdc++.h>
using namespace std;


using ll = long long;


int solve(int n, int k)
{    
    if (k > n) return 0;
    int ret = 1;
    for (int i = 1; i <= k; i++)
        ret = ret * (n + 1 - i) / i;
    for (int i = 1; i <= k; i++)
        ret *= n + 1 - i;
    return ret;
}


int main()
{    
    int n, k;
    cin >> n >> k; 
    int ans = solve(n, k);
    cout << ans << endl;
    return 0;
}
