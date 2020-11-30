size = 5
visited = [False]*size # Visited List initialized to False for 5 nodes
graph = [[1,2,4],[0,2,3],[3,1,0],[1,2],[0]] # Sample Graph
result = [] # Empty Result
stack = [] # empty
stack.append(4) 

while stack:
    print(stack)
    element = stack.pop()
    if visited[element]:
        continue
    visited[element] = True
    result.append(element)
    neighbors = graph[element]
    for next in neighbors:
        if not visited[next]:
            stack.append(next)


print(result)