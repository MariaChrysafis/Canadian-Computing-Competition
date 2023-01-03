import sys
sys.setrecursionlimit(200000)
def get_max (cur, prev) :
    tot = [colored[cur], 0]
    for nxt in adj[cur] :
        if nxt != prev :
            val = get_max(nxt, cur)
            if val[0] :
                tot[0] = True
                tot[1] += val[1] + 2
    return tot

def calc_depth (root) :
    vis = [False] * n
    q = [[root, 0]]
    while len(q) != 0 :
        p = q[-1]
        d[p[0]] = p[1];
        q.pop()
        for nxt in adj[p[0]] :
            if not vis[nxt] :
                vis[nxt] = True
                q.append([nxt, p[1] + 1])

n, m = map(int, input().split(' '))
adj = []
d = [0] * n
while len(adj) != n :
    adj.append([])
arr = list(map(int, input().split(' ')))
colored = [False] * n
for i in arr :
    colored[i] = True
for i in range(0, n - 1) :
    u, v = map(int, input().split(' '))
    adj[u].append(v)
    adj[v].append(u)
if m == 2 :
    calc_depth(arr[0])
    print(d[arr[1]])
else :
    deepest = 0
    calc_depth(0)
    for i in range(0, n) :
        if colored[i] and d[i] > d[deepest] :
            deepest = i
    calc_depth(deepest)
    myMax = 0
    for j in range(0, n) :
        if colored[j] :
            myMax = max(myMax, d[j])
    print(get_max(deepest, deepest)[1] - myMax)
