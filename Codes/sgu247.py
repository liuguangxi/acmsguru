# OEIS A169888

def S(p):
    t = 1
    for i in range(1, p + 1):
        t = t * (2 * p + 1 - i) // i
    t = (t - 2) // p + 2
    return t

N = int(input())
for _ in range(N):
    P = int(input())
    print(S(P))
