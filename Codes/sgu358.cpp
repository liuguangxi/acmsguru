#include <bits/stdc++.h>
using namespace std;


int main()
{
    int a[3], b[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        b[i] = a[1];
    }
    sort(b, b + 3);
    cout << b[1] << endl;
    return 0;
}
