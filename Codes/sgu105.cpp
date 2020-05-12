#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;
    int ans = (N - 1) / 3 * 2 + (N - 1) % 3;
    cout << ans << endl;
    return 0;
}
