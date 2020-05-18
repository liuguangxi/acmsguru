#include <bits/stdc++.h>
using namespace std;


string N;
int K;


void solve()
{
    int lenout = N.size() - K;
    int t = 0;
    for (int i = 1; i < (int)N.size() && t < K; i++) {
        while (N[i] > N[i - 1]) {
            N.erase(N.begin() + i - 1);
            if (++t == K) break;
            if (--i == 0) break;
        }
    }
    cout << N.substr(0, lenout) << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> K;
    solve();
    return 0;
}
