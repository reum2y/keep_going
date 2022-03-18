#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int n, m;

int board[501][501] = { 0, };
int visit[501][501] = { 0, };
int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };

int bfs(int y, int x) {
    int funcnt = 0;
    queue <pair <int, int> > q;
    q.push(make_pair(y, x));
    while (!q.empty()) {
        pair <int, int> now = q.front();
        q.pop();
        funcnt++;
        for (int i = 0; i < 4; i++) {
            int py = now.first + d_y[i];
            int px = now.second + d_x[i];
            if (0 <= py && py < n && 0 <= px && px < m && visit[py][px] == 0 && board[py][px] == 1) {
                visit[py][px] = 1;
                q.push(make_pair(py, px));

            }
        }
    }
    return funcnt;
}

int main() {
    int cnt = 0;
    cin >> n >> m;
    vector <int> v;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && visit[i][j] == 0) {
                visit[i][j] = 1;
                v.push_back(bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    cout << *max_element(v.begin(), v.end());

}