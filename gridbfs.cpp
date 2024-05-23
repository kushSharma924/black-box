#include <bits/stdc++.h>
using namespace std;

/*  Given a 2d array of chars where S represents the starting position,
    E represents the ending position, # represents a wall, and . represents
    a walkable area, what is the length of the shortest path from S to E? 
 */

// copy

struct point {
    int r; int c;
};

int bfs(vector<vector<char>>& grid) {
    // parsing input
    vector<vector<bool>> visited(grid.size());
    vector<vector<int>> dist(grid.size());
    int sr = -1; int sc = -1; int er = -1; int ec = -1;
    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
            dist[r].push_back(-1);
            if (grid[r][c] == 'S') {
                sr = r;
                sc = c;
            }
            if (grid[r][c] == 'E') {
                er = r;
                ec = c;
            }
            if (grid[r][c] == '#') visited[r].push_back(true);
            else visited[r].push_back(false);
        }
    }
    // actual algo
    queue<point> q;
    point p; p.r = sr; p.c = sc;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    q.push(p);
    dist[sr][sc] = 0;
    visited[sr][sc] = true;
    while (q.size() > 0) {
        point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = cur.r + dr[i];
            int cc = cur.c + dc[i];
            if (rr < 0 || rr >= grid.size() || cc < 0 || cc >= grid[0].size() || visited[rr][cc]) continue;
            point next; next.r = rr; next.c = cc;
            q.push(next);
            dist[rr][cc] = dist[cur.r][cur.c] + 1;
            visited[rr][cc] = true;
        }
    }
    return dist[er][ec];
}

// end copy

int main() {
    // usage
    vector<vector<char>> grid = {
        {'E', '#', '#', '.', 'S'},
        {'.', '#', '#', '.', '#'},
        {'.', '#', '#', '.', '#'},
        {'.', '#', '#', '.', '#'},
        {'.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#'}
    };
    int ans = bfs(grid);
    cout << ans << "\n";
}