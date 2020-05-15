#include <bits/stdc++.h>
using namespace std;


bool C[1000001];


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    int a, maxa = 0;
    bool flag = false;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        C[a] = true;
        maxa = max(maxa, a);
    }
    for (int i = maxa / 2; i >= 1; i--) {
        int t = 0;
        for (int j = i; j <= maxa; j += i) {
            if (C[j]) t++;
            if (t == 2) {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    return 0;
}
