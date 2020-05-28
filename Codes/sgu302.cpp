#include <bits/stdc++.h>
using namespace std;


string S;


void solve()
{
    stack<int> st;
    bool istag = false;
    string tag;
    for (char c : S) {
        if (istag) {
            if (c == '>') {
                istag = false;
                if (tag == "UP") st.push(1);
                else if (tag == "DOWN") st.push(0);
                else st.pop();
            } else {
                tag += c;
            }
        } else {
            if (c == '<') {
                istag = true;
                tag = "";
            } else {
                char co = (st.empty()) ? c : (st.top() == 1) ? toupper(c) : tolower(c);
                cout << co;
            }
        }
    }
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> S;
    solve();
    return 0;
}
