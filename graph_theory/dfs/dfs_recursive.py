size = 5
visited = [False]*size # Visited List initialized to False for 5 nodes
graph = [[1,2,4],[0,2,3],[3,1,0],[1,2],[0]] # Sample Graph
result = [] # Empty Result


def dfs(node):
    if visited[node]: # EXIT CASE (If given node has been visited)
        return 
    visited[node] = True # Mark unvisited node as visited 
    result.append(node) # Add newly visited node to the result
    neighbors = graph[node] # Initialize neighbors to adjacency list of newly visited node
    for next in neighbors: # For every node in neighbors , perform DFS
        dfs(next)

dfs(0) # Start node can be any node
print(result) # Display resulting list
