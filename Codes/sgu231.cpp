#include <bits/stdc++.h>
using namespace std;


void solve(int n)
{
    if (n <= 4) {
        cout << 0 << endl;
        return;
    }

    vector<bool> isprime(n + 1);
    vector<int> prime;
    vector<int> vb;
    int s = 0;

    fill(isprime.begin() + 2, isprime.end(), true);
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isprime[j] = false;
            prime.push_back(i);
        }
    }

    for (int b : prime) {
        if (2 + b > n)
            break;
        if (isprime[2 + b]) {
            s++;
            vb.push_back(b);
        }
    }
    cout << s << endl;
    for (int b : vb)
        cout << 2 << " " << b << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    cin >> N;
    solve(N);
    return 0;
}
