import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**9)

#초기화
n = int(input())
graph = [[] for _ in range(n+1)]

for _ in range(n - 1):
    a_node, b_node, weight = map(int, input().split())
    graph[a_node].append([b_node, weight])
    graph[b_node].append([a_node, weight])
    
    
#DFS로 구현 
def get_all_distance_from_node(now,now_weight):
    for leaf in graph[now]:
        next_node,next_weight = leaf
        if distance[next_node]== -1:
            distance[next_node] = now_weight + next_weight
            get_all_distance_from_node(next_node,now_weight + next_weight)

#임의 노드 1에서 가장 먼 노드찾기 => edge 노드 찾기
tmp_node = 1
distance = [-1]*(n+1)
distance[1] = 0
get_all_distance_from_node(tmp_node,0)


#edge 노드에서 다른 edge 노드를 찾아 거리 구하기 
edge_node = distance.index(max(distance))
distance = [-1] * (n+1)
distance[edge_node] = 0
get_all_distance_from_node(edge_node,0)
print(max(distance))