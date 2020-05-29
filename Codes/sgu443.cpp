#include <bits/stdc++.h>
using namespace std;


int keynum(int n)
{
    vector<int> fa;
    if (n % 2 == 0) {
        fa.push_back(2);
        while (n % 2 == 0) n /= 2;
    }
    int p = 3;
    while (p * p <= n) {
        if (n % p == 0) {
            fa.push_back(p);
            while (n % p == 0) n /= p;
        }
        p += 2;
    }
    if (n > 1) fa.push_back(n);
    int len = fa.size();
    int s = fa[len - 1];
    for (int i = 0; i < len - 1; i++) s -= fa[i];
    return s;
}


int main()
{
    int a, b;
    cin >> a >> b;
    if (keynum(a) > keynum(b)) cout << "a" << endl;
    else cout << "b" << endl;
    return 0;
}
