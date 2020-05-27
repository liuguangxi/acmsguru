#include <bits/stdc++.h>
using namespace std;


int A, Alpha, Beta, Gamma, M, K;


inline f(int x)
{
    return (Alpha * x * x + Beta * x + Gamma) % M;
}


int solve()
{
    if (K == 0) return A;
    int x1, x2, i, p, r;
    x1 = x2 = A % M;
    i = 0;
    do {
        x1 = f(x1);
        x2 = f(f(x2));
        i++;
        if (i == K) return x1;
    } while (x1 != x2);
    x1 = A % M;
    i = 0;
    while (x1 != x2) {
        x1 = f(x1);
        x2 = f(x2);
        i++;
    }
    p = 0;
    do {
        x2 = f(x2);
        p++;
    } while (x1 != x2);
    r = (K - i) % p;
    while (r > 0) {
        x1 = f(x1);
        r--;
    }
    return x1;
}


int main()
{
    cin >> A >> Alpha >> Beta >> Gamma >> M >> K;
    cout << solve() << endl;
    return 0;
}
