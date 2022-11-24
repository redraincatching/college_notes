# social networks
## elements of a social network
- nodes
representing actors/people/entities. often represented as points.
data is associated with nodes
may be _one mode_ (nodes are all of the same type) or _two mode_ (nodes represent two different things)

- edges (or ties)
representing the links or social ties between nodes. represented as a line
may be different types of edges
may have weight
can be directed or undirected

## data representation
two  main approaches
1) adjacency matrix (sociomatrix)
2) edge list

### adjacency matrix
equal number of rows and columns (the number of actors)
elements in the matrix represent a relation between actors (often binary)
conventionally, relationship is read by row -> column
main diagonal is blank

### edge list
if binary connections exist:
used to store connections between nodes in pairs (id_1, id_2)
can also store as list of connections for each id

if _undirected_, relationship is not stored in both directions
if _directed_, convention is to read from first entry to second entry
if _weighted_, store a triple
// may need to supplement with a list of nodes if some have no connections

###### software for operations on networks
pajek is pretty good

---

## Social network analysis
what is of interest at sna level?
1) properties of nodes
2) properties of relationships
3) properties of network

> ![[zachary_example.png]]
> "zachary" example network


---
### Some propeties of nodes
![[degree_centrality]]

![[betweenness_centrality]]

![[closeness_centrality]]

![[eigenvector centrality]]

#### Paths and reachability
an individual node a is "_reachable_" by another node b if there exists a set of connections by which we can traverse from b to a

if a is reachable from b, we say that there exists a "_path_" from a to b
the number of edges that one needs to traverse to get from a to b is the _path length_

_// in a directed graph, it may be that a is reachable by b, but b is not by a_

##### distance
length of paths between individual nodes
of interest are:
- average distance between nodes
- shortest path between nodes (geodesic distance)
- diameter of a network -> the longest of all shortest paths between nodes

paths can be found by matrix multiplication
if A is an adjacency matrix, $A^2$ will find all paths of length 2

---
### Some properties of relationships
- reciprocity: the tendency in a directed network for the edge (i,j) to exist if the edge (j,i) exists
- transistivity: the tendency of friends-of-friends to be friends
- preferential attachment (popularity): the tendency of nodes that are already central to gain edges at a rate greater than that of nodes which are not central
- clique: a densely connected group -> a subset of nodes in a network where every pair of nodes in that subset are interconnected

---
### Some properties of networks
- edge density
	ratio of number of actual edges to total number of possible edges in that network
	for a directed network:
		$n*(n-1)$   
	// where n is the number of nodes
for an undirected network:
		$\Large\frac{(n*(n-1))}{2}$
- clustering coefficient
	the ratio of the number of edges between neighbours of a node v to the number of possible edges between neighbours of node v
	// only meaningful for nodes with at least two edges
	// in all cases, 0 <= cc <= 1
	$\large{cc_1}$: friends
	$\large{cc_2}$: friends-of-friends
- homophily
	tendency of actors with similar traits to form ties
- modularity
	existence or lack thereof of a "community structure" -> clusters that are not densely connected to others, but densely connected within itself
- diameter
	(see above)
- network type
	classification of different types of networks

---
## Types of Networks
![[network_types_1.png]]
![[network_types_2.png]]
social networks all fall into this "small-world" topology
most nodes in this are reachable from every other node by a small number of steps

_for n nodes, approx log(n) steps on average_

> #algorithms 