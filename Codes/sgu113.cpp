#include <bits/stdc++.h>
using namespace std;


bool solve(int n)
{
    if (n <= 1) return false;
    int nf = 0;
    while (n % 2 == 0) {
        n /= 2;
        nf++;
    }
    int p = 3;
    while (p * p <= n) {
        while (n % p == 0) {
            n /= p;
            nf++;
        }
        p += 2;
    }
    if (n > 1) nf++;
    return nf == 2;
}


int main()
{
    int N;
    cin >> N;
    int x;
    while (N--) {
        cin >> x;
        if (solve(x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
