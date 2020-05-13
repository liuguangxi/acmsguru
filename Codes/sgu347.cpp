#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    cin >> N;
    string s;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(),
        [](const string &s1, const string &s2)
        {return s1 + s2 < s2 + s1;}
    );    
    for (const auto &x : v)
        cout << x;
    cout << endl;
    return 0;
}
