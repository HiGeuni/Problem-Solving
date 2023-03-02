from collections import deque

answer = 2e9

def differenceBetween(a, b):
    diff = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            diff += 1
    return diff == 1

def dfs(cur, end, depth, visited, words):
    global answer
    length = len(words)
    if cur == end:
        answer = min(answer, depth)
        return
    if depth == length:
        return
    for i in range(length):
        if differenceBetween(cur, words[i]) and not visited[i]:
            visited[i] = True
            dfs(words[i], end, depth + 1, visited, words)
            visited[i] = False
    return

def solution(begin, target, words):
    visited = [False for _ in range(len(words))]
    dfs(begin, target, 0, visited, words)
    return answer if answer != 2e9 else 0
