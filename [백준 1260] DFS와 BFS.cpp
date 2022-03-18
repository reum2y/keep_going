#include<iostream> 
#include<queue>
using namespace std;

#define MAX_VALUE 1001//N이 1~1000 이므로 1000번째 인덱스에 접근 -> 크기 1001까지 
int N, M, V; //정점개수, 간선개수, 탐색시작 정점 번호
int mat[MAX_VALUE][MAX_VALUE];
int visit[MAX_VALUE];

void dfs(int v);
void bfs(int v);

int main() {
    int x, y;//인접한 노드들
    cin >> N >> M >> V; //N은 노드개수, M은 간선의개수, V는 처음 위치의 기준이 되는 노드
    for (int i = 0; i < M; i++) { //간선의 개수만큼 서로 이어줄 x와 y노드를 입력받음
        cin >> x >> y;
        mat[x][y] = mat[y][x] = 1; //인접행렬 표시
    }

    dfs(V);
    cout << endl;
    bfs(V);

    return 0;
}
void dfs(int v) {
    cout << v << " ";
    visit[v] = 1; //방문한 노드 배열을 0->1
    for (int i = 1; i <= N; i++) { //노드번호로 접근하기 때문에 i=1부터 시작
        if (visit[i] == 1 || mat[v][i] == 0)
            continue;
        dfs(i); //만약 이미 방문한 노드였거나, 인접한 노드가 없다면 재귀


        // 반복문 안에서 i++을 하기위해선 아직 안간노드이거나, 인접해야지 다음노드로 갈수있음
        // 아직 방문하지 않은 노드이거나, 인접한 노드만 신경쓰겠다. 나머진 무시
        // 즉, if문 만족하지 않을경우(= 아직 방문하지 않은 노드이거나, 인접한 노드) continue문에 의해 반복문 블럭 제일 끝으로 온다음 다시 반복문 시작 
    }

}

void bfs(int v) {
    //리스트를 써서 pop(0)하게 되면 시간복잡도가 O(N)이다. 
    //그래서 시간복잡도가 O(1)인 queue 사용

    queue<int> q; //bfs에서는 q 사용
    q.push(v);
    visit[v] = 0; //방문한 노드를 1->0

    while (!q.empty()) { //q의 사이즈가 0인지 아닌지를 확인
        v = q.front(); //q에 가장 먼저 들어간 원소를 리턴
        cout << v << ' ';
        q.pop();//q에 가장 먼저 들어간 원소를 삭제
        for (int i = 1; i <= N; i++) {
            if (visit[i] == 0 || mat[v][i] == 0)
                continue;
            q.push(i);//q의 뒤(위)에 value값 추가
            visit[i] = 0;

        }
    }
}