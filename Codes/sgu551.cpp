#include <bits/stdc++.h>
using namespace std;


void solve(int n, int t1, int t2)
{
   bool act1 = true, act2 = true;
   int s1 = 0, s2 = 0, m = 0;
   while (m < n) {
       if (act1) s1 += t1;
       if (act2) s2 += t2;
       m += (s1 == s2) ? 2 : 1;
       act1 = (s1 <= s2);
       act2 = (s1 >= s2);
   }
   if (s1 != s2) m++;
   int f = max(s1, s2);
   cout << m << " " << f << endl;
}


int main()
{
    int N, T1, T2;
    cin >> N >> T1 >> T2;
    solve(N, T1, T2);
    return 0;
}
