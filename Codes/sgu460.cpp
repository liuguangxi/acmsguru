#include <bits/stdc++.h>
using namespace std;


string solve(const string &s)
{
    int len = s.size();
    if (s.substr(len-2) == "ch" || s[len-1] == 'x' || s[len-1] == 's' || s[len-1] == 'o')
        return s + "es";
    else if (s.substr(len-2) == "fe")
        return s.substr(0, len-2) + "ves";
    else if (s[len-1] == 'f')
        return s.substr(0, len-1) + "ves";
    else if (s[len-1] == 'y')
        return s.substr(0, len-1) + "ies";
    else
        return s + "s";
}


int main()
{
    int n;
    cin >> n;
    string w;
    while (n--) {
        cin >> w;
        cout << solve(w) << endl;
    }
    return 0;
}
