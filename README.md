# black-box

Welcome to the black-box!

The black-box contains a set of competitive programming data structures & algorithm templates that I've written for personal reference and as practice for contests on platforms such as Codeforces and Leetcode. 

Here's a list of the data structures / algorithms I've implemented so far (descriptions are intentionally vague):

# 1. KMP (Knuth-Morris-Pratt) Algorithm
- Let S be a string of size N and s be a string of size M (M <= N).
- KMP will find all occurences of s in S and store them in a vector v.
- The time complexity for KMP is **O(N+M)**.
- The space complexity for KMP is **O(M)**.
# 2. BFS (Breadth-First-Search)
- Let grid be an M x N matrix containing .'s (walkable spaces), #'s (walls), an S (the starting location), and an E (the ending location).
- BFS will find the length of the shortest path from S to E and return it.
- The time complexity for BFS is **O(M * N)** since each node is visited at most one time.
- The space complexity for BFS is **O(M * N)** since we maintain a visited matrix of dimensions M x N.
# 3. Binary Exponentiation
- Let a and b be two non-negative integers.
- Binary exponentation returns a ^ b mod 1000000007.
- The time complexity for binary exponentation is **O(log(N))** where N is TMax for integers (this comes out to 31 for 32 bit ints).
- The space complexity for binary exponentiation is **O(log(N))** since we maintain an array of size log(N).
# 4. DFS (Depth-First-Search)
- Let G = (V, E) be a graph with V vertices and E edges, and let S be a node in G.
- DFS will traverse G starting from S by going as deep into the graph as possible and then backtracking.
- The time complexity for DFS is **O(V + E)** since each node is visited at most once and each edge is traversed at most once.
- The space complexity for DFS is **O(V)** since we maintain a visited array of size V.
