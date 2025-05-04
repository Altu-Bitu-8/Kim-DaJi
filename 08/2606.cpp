#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;
int graph[MAX][MAX];
bool visited[MAX];
int n, m;

int bfs(int start) {
    queue<int> q;
    int infected = 0;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && graph[current][i] == 1) {
                q.push(i);
                visited[i] = true;
                infected++;
            }
        }
    }

    return infected;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1; // 양방향 연결
    }

    int result = bfs(1);
    cout << result;
    return 0;
}
