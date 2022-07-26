import sys
from collections import deque
input = sys.stdin.readline

N, Q = map(int,input().split())

idx = dict()

graph = [[] for _ in range(200005)]

transfer_node = []

station_info = [[] for _ in range(200005)]

cnt = 0
def naming(tt):
    global cnt
    if tt not in idx:
        idx[tt] = cnt
        cnt += 1
    return idx[tt]

for j in range(N):
    l = list(input().split())
    num = int(l[0])
    for i in range(1, num + 1):
        id = naming(l[i])
        station_info[id].append([j, i])
        if i > 1:
            id2 = naming(l[i-1])
            graph[id].append(id2)
            graph[id2].append(id)

for i in range(200005):
    if len(station_info[i]) > 1:
        transfer_node.append(i)
        
num_transfer_node = len(transfer_node)

dist = [[2000000000 for _ in range(200005)] for _ in range(num_transfer_node)]

for i in range(num_transfer_node):
    # 환승역 기준
    dq = deque()
    dq.append(transfer_node[i])
    dist[i][transfer_node[i]] = 0
    while len(dq) != 0:
        cur_node = dq.popleft()
        for node in graph[cur_node]:
            if dist[i][node] == 2000000000:
                dist[i][node] = dist[i][cur_node] + 2
                dq.append(node)

# print("transfer node : ", transfer_node)
# print("station_info : ", station_info[:10])
# print("dist : ", dist)

for _ in range(Q):
    _from, _to = input().split()
    fn = naming(_from)
    tn = naming(_to)

    ans = 2000000000
    # 환승 할 때
    for i in range(num_transfer_node):
        ans = min(ans, (dist[i][fn] + dist[i][tn]))
    # 안 할 떄
    if len(station_info[fn]) == 1 and len(station_info[tn]) == 1 and station_info[fn][0][0] == station_info[tn][0][0]:
        # 노선이 같을 경우
        # update
        ans = min(ans, abs(station_info[fn][0][1] - station_info[tn][0][1]) * 2)
    if ans >= 2000000000:
        ans = -1
    print(ans)
