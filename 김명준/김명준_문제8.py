from collections import deque
import sys 
input = sys.stdin.readline

n,m = map(int,input().split())
visited = list([0] * (m) for _ in range(n))
q = deque()
graph = []
for i in range(n):
    line = list(map(int, input().split()))
    for j in range(m):
        if line[j] == 9:
            q.append((i, j))
            visited[i][j] = 1
    graph.append(line)
            
dx = [-1,0,1,0]# 상 우 하 좌 
dy = [0,1,0,-1]


def bfs(): 
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = dx[i], dy[i]
            next_x, next_y = x + nx, y + ny
            
            while 0 <= next_x < n and 0 <= next_y < m:
                visited[next_x][next_y] = 1
                
                if graph[next_x][next_y] == 9:
                    break
                
                if graph[next_x][next_y] == 3:
                    nx, ny = -ny, -nx
                    
                elif graph[next_x][next_y] == 4:
                    nx, ny = ny, nx
                    
                elif (graph[next_x][next_y] == 1 and nx == 0) or (graph[next_x][next_y] == 2 and ny == 0):
                    break
                next_x += nx
                next_y += ny
                
    answer = 0
    for ans in visited:
        answer += ans.count(1)
    print(answer)
bfs()






# def change_dir(x,y,dir):
    
#     if graph[x][y] == 1:
#         if dir in [0,2]:
#             return dir 
#         else: return (dir + 2)%4
    
#     elif graph[x][y] == 2:
#         if dir in [1,3]:
#             return dir 
#         else: return (dir + 2)%4
    
#     elif graph[x][y] == 3:
#         return (dir + 1 ) % 4 if dir in [0,2] else (dir + 3) % 4  
    
#     elif graph[x][y] == 4:
#         return (dir + 1 ) % 4 if dir in [1,3] else (dir + 3) % 4  
    
#     else : 
#         return dir

# def is_in_range(x, y):
#     return 0 <= x < n and 0 <= y < m

# while q:
#     now_x,now_y = q.popleft()
#     visited[now_x][now_y] = 9
#     for i in range(4):
#         next_x = now_x + dx[i]
#         next_y = now_y + dy[i]
#         dir = i
#         while True :
#             if not is_in_range(next_x,next_y)  :
#                 break
#             if graph[next_x][next_y] == 9:
#                 break
#             if graph[next_x][next_y] in [1,2] and visited[next_x][next_y] == dir + 1 :
#                 break
#             if graph[next_x][next_y] in [3,4]:
#                 if visited[next_x][next_y] == dir + 1 :
#                     break
#                 tmp_dir = change_dir(next_x,next_y,dir)
#                 if visited[next_x][next_y] == tmp_dir + 1 :
#                     break

#             visited[next_x][next_y] = dir+1
#             dir = change_dir(next_x,next_y,dir)
#             next_x += dx[dir]
#             next_y += dy[dir]  

# ans = 0
# for line in visited:
#     ans += m - line.count(0)
# print(ans)





