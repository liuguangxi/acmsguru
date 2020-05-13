#include <bits/stdc++.h>
using namespace std;


using ll = long long;


ll C(int n)
{
    ll ret = 1;
    for (int i = 1; i <= n; i++)
        ret = ret * (2 * n + 1 - i) / i;
    ret /= n + 1;
    return ret;
}


int main()
{    
    int k;
    cin >> k; 
    ll N = C(k);
    int P = k + 1;
    cout << N << " " << P << endl;
    return 0;
}
