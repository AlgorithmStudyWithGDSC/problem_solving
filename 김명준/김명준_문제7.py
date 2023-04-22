import sys

INF_MIN = -sys.maxsize
n, m = map(int, input().split())
graph = [[0 for j in range(m + 2)] for i in range(n + 2)]
dp = [[[INF_MIN for j in range(m + 2)] for i in range(n + 2)] for k in range(2)]

for i in range(1, n + 1): 
    graph[i][1:m+1]=list(map(int,input().split()))

dp[0][n][1], dp[1][n][m] = graph[n][1], graph[n][m]

#상승 
for i in range(n, 0, -1):
    for j in range(1, m + 1, 1):
        if i == n and j == 1: continue  #밑과 왼쪽을 비교해서 출발한 비행  중 가장 점수가 높은 것과 현재 점수를 합하여 지금까지 상승방향으로 도달한 위치에서 얻을 수 있는 가장 높은 점수다. 
        dp[0][i][j] = max(dp[0][i + 1][j], dp[0][i][j - 1]) + graph[i][j]
#하강 
for i in range(n, 0, -1):
    for j in range(m, 0, -1):
        if i == n and j == m: continue  # 밑과 오른쪽을 비교해서 골인한 비행 중 가장 점수가 높은 것과 현재 점수를 합하여 마지막 점수에서 지금까지 하강 방향으로 도달한 위치에서 얻을 수 있는 가장 높은 점수다. 
        dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j + 1]) + graph[i][j]

ans = INF_MIN
for i in range(1, n + 1):
    for j in range(1, m + 1):
        ans = max(ans, dp[0][i][j] + dp[1][i][j])
print(ans)



# # 앞위 아래앞 밖에 못 움직인다. 아래로 내려가는 순간 계속 내려가야한다. n 세로 
# #오른쪽으로는 항상 갈 수 있다. 
# from collections import deque 
# n,m = map(int,input().split())
# graph = [list(map(int,input().split())) for _ in range(n)]
# start_point_x,start_point_y = n-1,0
# #위 오른쪽 밑
# dx = [-1,0,1] 
# dy = [0,1,0]

# result = []
# def maximum_route(x,y):
#     q = deque()
#     q.append([x,y,graph[x][y],True])
#     while q :
#         now_x,now_y, now_weight,is_up = q.popleft()
#         if now_x == n-1 and now_y == m-1 :
#             result.append(now_weight)
#             continue

#         if is_up: # 상승
#             for i in range(3):
#                 if i == 2:
#                     is_up = False
#                 next_x = now_x + dx[i]
#                 next_y = now_y + dy[i]

#                 if is_up and 0<= next_x and next_x <=n-1 and 0<= next_y and next_y <=m-1:
#                     q.append([next_x,next_y,now_weight+graph[next_x][next_y],is_up])
#                 if is_up == False and 0<= next_x and next_x <=n-1 and 0<= next_y and next_y <=m-1:
#                     q.append([next_x,next_y,(now_weight+graph[next_x][next_y]+graph[now_x][now_y]),is_up])

#         else: #하강
#             for i in range(1,3):
#                 next_x = now_x + dx[i]
#                 next_y = now_y + dy[i]
#                 if 0<= next_x and next_x <=n-1 and 0<= next_y and next_y <=m-1:
#                     q.append([next_x,next_y,now_weight+graph[next_x][next_y],is_up])

# maximum_route(start_point_x,start_point_y)
# print(max(result))
