#include <bits/stdc++.h>
using namespace std;


void solve(int n)
{
    vector<int> v(n + 1);
    v[1] = 1;
    for (int i = 1; i <= n / 2; i++) {
        int c = v[i] + 1;
        for (int j = i * 2; j <= n; j += i) v[j] = c;
    }
    int m = *max_element(v.begin(), v.end());
    cout << m << endl;
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    cin >> N;
    solve(N);
    return 0;
}
