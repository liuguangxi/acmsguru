#include <bits/stdc++.h>
using namespace std;


void solve(int n)
{
    if (n % 2 == 0) {
        cout << "No solution" << endl;
        return;
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<int> v;
    while (n > 1) {
        if (n % 4 == 1) {
            n = (n + 1) / 2;
            v.push_back(1);
        } else {
            n = (n - 1) / 2;
            v.push_back(2);
        }
    }
    reverse(v.begin(), v.end());
    cout << v.size() << endl;
    for (int x : v) cout << x << " ";
    cout << endl;
}


int main()
{
    int N;
    cin >> N;
    solve(N);
    return 0;
}
