// BFS Grid implementation
// DWITE '07 R4 #4 - Shortest path around
// https://dmoj.ca/problem/dwite07c4p4

#include <bits/stdc++.h>
using namespace std;

[[maybe_unused]] char grid[10][10];
bool visited[10][10];

void solve() {
    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;

    for (int k = 0; k < 10; k++) {
        string line;
        cin >> line;
        for (int j = 0; j < line.length(); j++) {
            grid[k][j] = line[j];
            if (line[j] == 'X') {
                if (start_x == -1) {
                    start_x = k;
                    start_y = j;
                }
                end_x = k;
                end_y = j;
            }
        }
    }

    string skip;
    cin >> skip; // Skip grid breaker

//    for (int i =0 ; i < 10; i++) {
//        for (int j =0 ; j < 10; j++)
//            cout << grid[i][j];
//        cout << endl;
//    }
//    cout << start_x << " " << start_y << endl;
//    cout << end_x << " " << end_y << endl;

    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        steps ++;
        for (int k =0; k < size; k++) { // this size is how many neighbours does current have
            auto cur = q.front();
            q.pop();
            int cur_x = cur.first, cur_y = cur.second;
            int dir[][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};

            for (int i = 0; i < 8; i++) {
                int x = cur_x + dir[i][0];
                int y = cur_y + dir[i][1];

                if (x < 0 || y < 0 || x >=10 || y>=10) continue; // Check boundaries
                if (grid[x][y] == '#') continue;
                if (visited[x][y]) continue;

                q.push({x, y});
                visited[x][y] = true;

                if (x == end_x && y == end_y) {
                    cout << steps << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++)
        solve();

    return 0;
}
