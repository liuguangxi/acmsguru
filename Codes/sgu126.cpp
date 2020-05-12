#include <bits/stdc++.h>
using namespace std;


int solve(int a, int b)
{
    int g = __gcd(a, b);
    int s = (a + b) / g;
    if ((s & (s - 1)) == 0)
        return __builtin_popcount(s - 1);
    else
        return -1;
}


int main()
{
    int A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;
    return 0;
}
