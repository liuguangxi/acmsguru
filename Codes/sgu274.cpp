#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    string S;
    cin >> N;
    getline(cin, S);
    regex pat("^([\\w\\-]+\\.)*([\\w\\-]+)@([\\w\\-]+\\.)+([A-Za-z]{2,3})$");
    for (int i = 0; i < N; i++) {
        getline(cin, S);
        if (regex_match(S, pat))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
