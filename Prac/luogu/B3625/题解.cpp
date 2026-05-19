#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

struct coord {
    int x, y;
};

bool check(const vector<string>& maze, const vector<vector<bool>>& maze_tmp, coord node, int n, int m) {
    if (node.x <= 0 || node.x > n || node.y <= 0 || node.y > m) return false;
    
    if (maze_tmp[node.x - 1][node.y - 1]) return false;
    if (maze[node.x - 1][node.y - 1] == '#') return false;
    
    return true;
}

bool bfs(const vector<string>& maze, vector<vector<bool>>& maze_tmp, int n, int m) {
    queue<coord> q;
    q.push({1, 1});
    maze_tmp[0][0] = true; 

    while (!q.empty()) {
        coord tmp = q.front();
        q.pop(); 

        if (tmp.x == n && tmp.y == m) return true;
        
        for (int i = 0; i < 4; i++) {
            coord next_node = {tmp.x + dx[i], tmp.y + dy[i]};
            
            if (check(maze, maze_tmp, next_node, n, m)) {
                q.push(next_node);
                maze_tmp[next_node.x - 1][next_node.y - 1] = true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<string> maze(n); 
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    
    vector<vector<bool>> maze_tmp(n, vector<bool>(m, false));

    if (bfs(maze, maze_tmp, n, m)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

/*
BFS典型例题

合法性检查的规则：先检查是否越界，再检查是否visited，再检查题目特有的条件
*/