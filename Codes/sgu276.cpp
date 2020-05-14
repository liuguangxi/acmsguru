#include <bits/stdc++.h>
using namespace std;


int solve(int s, int p)
{
    if (p <= s) return 0;
	int d = p - s;
	if (d >= 1800) return 4;
	else if (d >= 900) return 3;
	else if (d >= 300) return 2;
	return 1;
}


int main()
{
    int S, P;
	cin >> S >> P;
	cout << solve(S, P) << endl;
    return 0;
}
