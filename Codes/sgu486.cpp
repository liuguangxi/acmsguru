#include <bits/stdc++.h>
using namespace std;


int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    int b = 0, c = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (n1[i] == n2[j]) {
                if (i == j)
                    b++;
                else
                    c++;
            }
        }
    }
    cout << b << " " << c << endl;
    return 0;
}
