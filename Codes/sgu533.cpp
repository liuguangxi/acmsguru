#include <bits/stdc++.h>
using namespace std;


int solve(int n)
{
    if (n < 30)
        return (n == 21) ? 1 : -1;
    n -= 30;
    return (n % 14 <= 10) ? (n / 14 + 2) : -1;
}


int main()
{
    int N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}
