#include <bits/stdc++.h>
using namespace std;


int N;


void solve()
{
    int k = N + 1 - N % 2;
    if (N % 2 == 1) {
        for (int i = 0; i < N / 2; i++) {
            cout << k;
            k += 2;
            for (int j = 0; j <= i; j++) {
                cout << " " << i+1+(N-1)*j << " " << N-i+(N+1)*j;
                cout << " " << (N-1-i)*N+1+(N+1)*j << " " << (N-i)*N+(N-1)*j;
            }
            cout << endl;
        }
        for (int i = 0; i < N / 2; i++) {
            cout << k;
            k += 2;
            int x = i * N + N / 2 + 1;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < N / 2 - i; k++) {
                    cout << " " << x;
                    x = (j <= 1) ? (x + N + 2*j-1) : (x - N + 5-2*j);
                }
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < N / 2; i++) {
            cout << k;
            k += 2;
            for (int j = 0; j <= i; j++) {
                cout << " " << i+1+(N-1)*j;
                if (N > 2) cout << " " << (N-i)*N+(N-1)*j;
            }
            for (int j = 0; j < i; j++)
                cout << " " << N+1-i+(N+1)*j << " " << (N-i)*N+1+(N+1)*j;
            cout << endl;
        }
        for (int i = 0; i < N / 2 - 1; i++) {
            cout << k;
            k += 2;
            int x = i * N + N / 2 + 1;
            for (int k = 0; k < N / 2 - i; k++) {
                cout << " " << x;
                x += N - 1;
            }
            for (int k = 0; k < N / 2 - i - 1; k++) {
                cout << " " << x;
                x += N + 1;
            }
            for (int k = 0; k < N / 2 - i; k++) {
                if (!(i == N / 2 - 2 && k == N / 2 - i - 1)) cout << " " << x;
                x -= N - 1;
            }
            for (int k = 0; k < N / 2 - i - 1; k++) {
                cout << " " << x;
                x -= N + 1;
            }
            cout << endl;
        }
        cout << k << " " << N*N/2-N/2+1 << " " << N*N/2+N/2 << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    solve();
    return 0;
}
