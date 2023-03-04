import collections
graph = collections.defaultdict(list)
answer = []

def go(s):
    while graph[s]:
        go(graph[s].pop(0))

    if not graph[s]:
        answer.append(s)
        return

def solution(tickets):
    for a,b in tickets:
        graph[a].append(b)
    for a, b in graph.items():
        graph[a].sort()
        
    go("ICN")

    return answer[::-1]
