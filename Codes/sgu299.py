N = int(input())
v = []
for _ in range(N):
    v.append(int(input()))
v.sort()
found = False
for i in range(0, N - 2):
    if v[i] + v[i + 1] > v[i + 2]:
        found = True
        print(v[i], v[i + 1], v[i + 2])
        break
if not found:
    print(0, 0, 0)
