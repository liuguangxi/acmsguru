#include <bits/stdc++.h>
using namespace std;


string S;


void solve()
{
    list<char> lst;
	auto p = lst.begin();
	for (char c : S) {
		if (c == 'L') {
			if (p != lst.begin()) p--;
		} else if (c == 'R') {
			if (p != lst.end()) p++;
		} else {
			lst.insert(p, c);
		}
	}
	for (char c : lst) cout << c;
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> S;
    solve();
    return 0;
}
