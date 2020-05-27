#include <bits/stdc++.h>
using namespace std;


string S;


int solve()
{
    int st = 0, num = 0;
    for (char c : S) {
        if (c == '(' || c == ')') num++;
        if (st == 0) {
            if (c == '(') st = 1;
        } else {
            if (c == ')') {
                num -= 2;
                st = 0;
            } else if (c == '-' || c == ':' || c == ',' || c == ';') {
                st = 0;
            }
        }
    }
    return num;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    getline(cin, S);
    cout << solve() << endl;
    return 0;
}
