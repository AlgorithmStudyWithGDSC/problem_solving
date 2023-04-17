import sys
sys.setrecursionlimit(10**6)

def find_parent_node(now,tree,parents):
    for leaf in tree[now]:
        if parents[leaf]==0:
            parents[leaf] = now
            find_parent_node(leaf,tree,parents)


n = int(input())
tree = list([] for _ in range(n+1))

for _ in range(n-1):
    connecting_conode,connected_node = map(int,input().split())
    tree[connecting_conode].append(connected_node)
    tree[connected_node].append(connecting_conode)

root_node = 1 
parents = [0] * (n+1)
find_parent_node(root_node,tree,parents)
for parent in parents[2:]:
    print(parent)

