import sys

input = sys.stdin.readline


def count_air(graph: list, row: int, col: int) -> list:
    tmp = []
    for i in range(row):
        for j in range(col):
            if graph[i][j] == 9:
                tmp.append((i, j))

    return tmp


def change_dir(dir: int, obj: int) -> int:
    if obj == 1:
        return dir if dir % 2 == 0 else -1
    elif obj == 2:
        return dir if dir % 2 == 1 else -1
    elif obj == 3:
        return dir + 1 if dir % 2 == 0 else dir - 1
    elif obj == 4:
        return (dir + 1) % 4 if dir % 2 == 1 else (dir + 3) % 4


def count_seat(graph: list, x: int, y: int, dir: int) -> int:
    seat = 0
    dx, dy = DIRECTION[dir]
    nx, ny = x + dx, y + dy

    while 0 <= nx < row and 0 <= ny < col:
        if graph[nx][ny] != 0:
            dir = change_dir(dir, graph[nx][ny])
            if dir == -1:
                if not visited[nx][ny]:
                    seat += 1
                    visited[nx][ny] = True
                break
            else:
                dx, dy = DIRECTION[dir]

        if not visited[nx][ny]:
            seat += 1
            visited[nx][ny] = True
        nx += dx
        ny += dy

    return seat


def solution(graph: list, row: int, col: int) -> int:
    air_list = count_air(graph, row, col)
    answer = 0
    if not air_list:
        return answer
    else:
        for x, y in air_list:
            answer += 1  # 에어컨의 위치 이므로 += 1
            visited[x][y] = True  # 에어컨 위치 방문 처리
            for i in range(4):
                answer += count_seat(graph, x, y, i)

    return answer


if __name__ == "__main__":
    row, col = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(row)]
    visited = [[False] * col for _ in range(row)]
    DIRECTION = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    print(solution(graph, row, col))
