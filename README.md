# black-box

Welcome to the black-box!

The black-box contains a set of competitive programming data structures & algorithm templates that I've written for reference and as practice for contests such as Codeforces and Leetcode. 

Here's a list of the data structures / algorithms I've implemented so far:

# 1. KMP (Knuth-Morris-Pratt) Algorithm
- Let S be a string of size N and s be a string of size M (M <= N).
- KMP will find all occurences of s in S and store them in a vector v.
- The time complexity for KMP is O(N+M).
- The space complexity for KMP is O(M).
# 2. BFS (Breadth-First-Search)
- Let grid be an M x N matrix containing .'s (walkable spaces), #'s (walls), an S (the starting location), and an E (the ending location).
- BFS will find the length of the shortest path from S to E and return it.
- The time complexity for BFS is O(M * N) since each node is visited at most one time.
- The space complexity for BFS is O(M * N) since we maintain a visited matrix of dimensions M x N.
