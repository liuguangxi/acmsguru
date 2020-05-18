#include <bits/stdc++.h>
using namespace std;


int N, M;


inline int bin2gray(int b)
{
    return b ^ (b >> 1);
}


void solve()
{
    for (int i = 0; i < (1 << N); i++) {
        int gi = bin2gray(i);
        for (int j = 0; j < (1 << M); j++) {
            int gj = bin2gray(j) << N;
            cout << (gj | gi) << " ";
        }
        cout << "\n";
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    solve();
    return 0;
}
