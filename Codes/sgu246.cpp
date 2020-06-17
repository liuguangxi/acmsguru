#include <bits/stdc++.h>
using namespace std;


int main()
{
    int M, K;
    cin >> M;
    K = M / 2 + 1;
    if (K % 3 == 2) K--;
    cout << K << endl;
    return 0;
}
