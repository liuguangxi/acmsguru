#include <bits/stdc++.h>
using namespace std;


int main()
{
    int K;
    cin >> K;
    int s;
    if (K == 1) {
        s = 8;
    } else {
        s = 1;
        if (K % 3 == 1) {
            s += 2;
            if (K % 6 == 1) s++;
        }
    }
    cout << s << endl;
    return 0;
}
