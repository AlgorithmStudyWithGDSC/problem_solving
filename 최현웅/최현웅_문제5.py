import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def solution(tree: list, parent_list: list, curr: int) -> None:
    for next in tree[curr]:
        if not parent_list[next]:
            parent_list[next] = curr
            solution(tree, parent_list, next)


if __name__ == "__main__":
    n = int(input())
    tree = [[] for _ in range(n + 1)]
    parent_list = [0] * (n + 1)
    for _ in range(n - 1):
        a, b = map(int, input().split())
        tree[a].append(b)
        tree[b].append(a)

    solution(tree, parent_list, 1)

    for parent in parent_list[2:]:
        print(parent)
