#include <bits/stdc++.h>
using namespace std;


void solve(int n, int m)
{
    const int Days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m > 12 || n > Days[m]) {
        cout << "Impossible" << endl;
        return;
    }

    int k = n - 1;
    for (int i = 1; i < m; i++)
        k += Days[i];
    k = (k % 7) + 1;
    cout << k << endl;
}


int main()
{
    int N, M;
    cin >> N >> M;
    solve(N, M);
    return 0;
}
