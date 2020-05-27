#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N, M, Si;
    int s = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> Si;
        s += Si;
    }
    s %= N;
    cout << s << endl;
    return 0;
}
