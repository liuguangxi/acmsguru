def calc(v, k):
    if k == 0:
        return 1
    n = len(v)
    f = [[0 for i in range(k + 1)] for j in range(n)]
    f[n - 1][1] = v[n - 1] - k + 1
    for i in range(n - 2, -1, -1):
        f[i][1] = v[i] - k + 1 + f[i + 1][1]
    for m in range(2, k + 1):
        for i in range(n - m, -1, -1):
            f[i][m] = (v[i] - k + m) * f[i + 1][m - 1] + f[i + 1][m]
    return f[0][k]


N, K = map(int, input().split())
vo = [i // 2 * 2 + 1 for i in range(N)]
ve = [i // 2 * 2 + 2 for i in range(N - 1)]
s = 0
for i in range(K + 1):
    if i <= N and K - i <= N - 1:
        s += calc(vo, i) * calc(ve, K - i)
print(s)
