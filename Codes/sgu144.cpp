#include <bits/stdc++.h>
using namespace std;


int main()
{
    int X, Y;
    double Z;
    scanf("%d%d%lf", &X, &Y, &Z);
    double t = Z / (60 * (Y - X));
    double ans = t * (2 - t);
    printf("%.7f\n", ans);
    return 0;
}
