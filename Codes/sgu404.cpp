#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    string s;
    vector<string> v;
    for (int i = 0; i < M; i++) {
        cin >> s;
        v.push_back(s);
    }
    cout << v[(N - 1) % M] << endl;
    return 0;
}
