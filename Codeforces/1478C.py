nTest = int(input())

for iTest in range(nTest):
    n = int(input())
    x = input()
    a = []
    d = {}
    for i in x.split():
        a.append(int(i))
        if int(i) not in d:
            d[int(i)] = 1
        else:
            d[int(i)] += 1
    f = 1
    for i in d:
        if d[i] != 2:
            f = 0
            break
    if not f:
        print("NO")
        continue
    a.sort()
    s = set()
    for x in a:
        s.add(x)
    if len(s) != n:
        print("NO")
        continue
    a.clear()
    for x in s:
        a.append(x)
    a.sort()
    a.reverse()
    sum = 0
    
    for i in range(n):
        if a[i] - 2 * sum <= 0 or (a[i] - 2 * sum) % (2 * (n - i)) != 0:
            f = 0
            break
        sum += (a[i] - 2 * sum) / (2 * (n - i))
    if f:
        print("YES")
    else:
        print("NO")