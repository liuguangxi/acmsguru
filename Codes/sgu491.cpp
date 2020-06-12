#include <bits/stdc++.h>
using namespace std;


const int MaxN = 100000;
int N;
vector<int> vd[MaxN];


int solve()
{
    if (N <= 2) return 0;

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i)
            vd[j].push_back(i);
    }

    int Nsqrt = (int)sqrt((double)N + 0.5);
    int N2 = N / 2;
    int s = N - 2;
    for (int B = 2; B <= Nsqrt; B++) {
        for (int A = 2; A < B; A++) {
            if (N % __gcd(B, A) == 0) s++;
        }
    }
    for (int B = Nsqrt + 1; B <= N2; B++) {
        set<int> sd;
        for (int x = N - B; x > 0; x -= B) {
            for (int d : vd[x]) {
                if (d >= B) break;
                sd.insert(d);
            }
        }
        s += sd.size();
    }
    for (int B = N2 + 1; B < N; B++)
        s += vd[N - B].size();
    return s;
}


int main()
{
    cin >> N;
    cout << solve() << endl;
    return 0;
}
