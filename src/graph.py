class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, v1, v2):
        if v1 not in self.graph:
            self.graph[v1] = []
        if v2 not in self.graph:
            self.graph[v2] = []
        self.graph[v1].append(v2)
        self.graph[v2].append(v1)

    def dfs(self, start):
        visited = []
        stack = [start]
        while stack:
            node = stack.pop()
            if node not in visited:
                visited.append(node)
                for neighbor in self.graph.get(node, []):
                    if neighbor not in visited:
                        stack.append(neighbor)
        return visited

    def __iter__(self):
        return iter(self.dfs(list(self.graph.keys())[0]) if self.graph else [])
