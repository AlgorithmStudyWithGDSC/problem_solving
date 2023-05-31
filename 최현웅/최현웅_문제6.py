import sys

input = sys.stdin.readline


def solution(tree: list, visited: list, curr: int, tmp: int) -> None:
    global leaf, dist
    if all(visited[connected[0]] for connected in tree[curr]):
        if dist < tmp:
            leaf = curr
            dist = tmp
        return

    for node, weight in tree[curr]:
        if not visited[node]:
            visited[node] = True
            solution(tree, visited, node, tmp + weight)
            visited[node] = False


if __name__ == "__main__":
    n = int(input())
    tree = [[] for _ in range(n + 1)]
    for _ in range(n):
        connected = list(map(int, input().split()))
        node = connected[0]
        connected = connected[1:-1]

        for i in range(0, len(connected), 2):
            number, weight = connected[i : i + 2]
            tree[node].append([number, weight])

    dist = leaf = 0
    visited = [False] * (n + 1)
    visited[1] = True
    solution(tree, visited, 1, dist)

    dist = 0
    visited = [False] * (n + 1)
    visited[leaf] = True
    solution(tree, visited, leaf, 0)
    print(dist)
