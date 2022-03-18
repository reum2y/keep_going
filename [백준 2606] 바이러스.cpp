#include <iostream>
#include<queue>
using namespace std;
#define MAX 101

int n, m;
int cnt = 0;
int arr[MAX][MAX];
int visit[MAX];
queue<int> q;

void bfs(int v) {
    q.push(v);
    visit[v] = 1;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0 && arr[v][i] == 1) {
                q.push(i);
                visit[i] = 1;
                cnt++;

            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }
    bfs(1);
    cout << cnt;
    return 0;
}