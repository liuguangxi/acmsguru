#include <bits/stdc++.h>
using namespace std;


void solve(int n)
{
    vector<bool> isprime(n + 1);
    vector<int> superprime;
    vector<int> fc(n + 1);
    vector<int> fv(n + 1);

    fill(isprime.begin() + 2, isprime.end(), true);
    int k = 0;
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isprime[j] = false;
            if (isprime[++k])
                superprime.push_back(i);
        }
    }

    const int Inf = 0x3f3f3f3f;
    fill(fc.begin() + 1, fc.end(), Inf);
    for (int p : superprime) {
        for (int i = p; i <= n; i++) {
            if (fc[i - p] + 1 < fc[i]) {
                fc[i] = fc[i - p] + 1;
                fv[i] = p;
            }
        }
    }

    if (fc[n] == Inf) {
        cout << 0 << endl;
    } else {
        cout << fc[n] << endl;
        int r = n;
        while (r > 0) {
            cout << fv[r] << " ";
            r -= fv[r];
        }
        cout << endl;
    }
}


int main()
{
    int N;
    cin >> N;
    solve(N);
    return 0;
}
