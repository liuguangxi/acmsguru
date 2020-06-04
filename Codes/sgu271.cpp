#include <bits/stdc++.h>
using namespace std;


int N, M, K;


void solve()
{
    vector<string> v;
    deque<string> q;
    stack<string> st;
    string s, t;
    bool flag = false;

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (i < K) q.push_back(s);
        else v.push_back(s);
    }
    for (int i = 0; i < M; i++) {
        cin >> t;
        if (t[0] == 'R') {
            flag = !flag;
        } else {
            s = t.substr(4, t.size() - 5);
            if (!flag) {
                q.push_front(s);
                if ((int)q.size() > K) {
                    st.push(q.back());
                    q.pop_back();
                }
            } else {
                q.push_back(s);
                if ((int)q.size() > K) {
                    st.push(q.front());
                    q.pop_front();
                }
            }
        }
    }

    if (flag) {
        while (!q.empty()) {
            cout << q.back() << '\n';
            q.pop_back();
        }
    } else {
        while (!q.empty()) {
            cout << q.front() << '\n';
            q.pop_front();
        }
    }
    while (!st.empty()) {
        cout << st.top() << '\n';
        st.pop();
    }
    for (const auto &x : v) cout << x << '\n';
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M >> K;
    solve();
    return 0;
}
