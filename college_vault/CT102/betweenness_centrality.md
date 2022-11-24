#### betweenness centrality
the number of times that a node acts as a "bridge" along the shortest path between nodes
nodes that have a _high probability of being on a randomly chosen shortest path between two randomly chosen nodes_ have a high betweenness centrality

![[betweenness_centrality.png]]

##### calculating betweenness centrality
1) for each pair of nodes (s, t), calculate the shortest paths between them
2) for each pair, determine the fraction of shortest paths that pass through the vertex in question
3) sum this fraction over all pairs of vertices (s, t)