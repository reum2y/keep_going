#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 26
using namespace std;

int N, cnt; //단지크기와 단지 내 집 크기 기록용 cnt
string arr[MAX]; //입력용 단지
int visited[MAX][MAX];//방문 기록용 배열

int dx[4] = { 0,0,-1,1 }; //상하좌우 x축방향
int dy[4] = { 1,-1,0,0 }; //상하좌우 y축방향

vector<int> v;
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push({ x, y }); //큐에 좌표 삽입
    visited[x][y] = 1; //입력받은 좌표 방문
    cnt++;

    while (!q.empty()) { //모든 좌표를 탐색할 때까지 반복
        //큐의 front좌표를 현재좌표로 지정
        int a = q.front().first;
        int b = q.front().second;

        //큐의 front좌표 제거
        q.pop();

        //현재 좌표와 상하좌우로 인접한 좌표 확인
        for (int i = 0; i < 4; i++) {
            int next_x = a + dx[i];
            int next_y = b + dy[i];
            //인접한 좌표가 단지 내에 존재하는지, 방문한적 있는지, 인접한지(이동가능한지)
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N
                && visited[next_x][next_y] == 0 && arr[next_x][next_y] == '1') {
                q.push({ next_x, next_y });//인접좌표 큐에 삽입
                visited[next_x][next_y] = 1; //인접좌표 방문한것으로 저장
                cnt++; //카운터 ++
            }
        }
    }

}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '1' && visited[i][j] == 0) { //단지가 1(인접)이고 방문한적 없으면
                cnt = 0;
                bfs(i, j);
                v.push_back(cnt);//벡터에 마지막 원소뒤에 cnt를 삽입
                //처음에 좌표 (0,0)에서 시작한것의 인접한 점들(단지 내 집)이 총 7개.(cnt=7)
                //그럼 벡터 v에 7들어감
                //그리고 다시 인접한 좌표가 모여있는 지점을 찾음
                //그 다음 좌표에서 인접한 점들이 총 8개(cnt=8)
                //근데 이전에 cnt=7이였으니까 다시 0으로 바꿔준 다음 bfs함수 호출해야됨
                //안그러면 누적되니까!
                //그렇게 계속 반복...
            }
        }
    }

    sort(v.begin(), v.end()); //v를 오름차순으로 정렬

    cout << v.size() << endl; //v 사이즈 (단지 수)
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

}