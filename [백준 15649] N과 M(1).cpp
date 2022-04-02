#include <iostream>
using namespace std;

//문제의 N과 M의 제한이 (1 ≤ M ≤ N ≤ 8) 으로 매우 작으므로 백트래킹 가능 
int N, M;
int arr[9];
int visit[9] = { 0, };
//1부터 n까지 자연수 중 m개를 중복없이 고르기
//dfs를 이용한 백트래킹
//dfs는 스택이나 재귀를 이용 - 그중 재귀 선택

void dfs(int k) {//현재 위치
    if (k == M) {//목표인 M까지 도달했다면
        for (int i = 0; i < M; i++)
            cout << arr[i] << " " << "\n";
        //cout << "\n";
    }

    else {//목표에 도달하지 않았다면
        for (int i = 1; i <= N; i++) {
            if (visit[i] != 1)//방문 안했다면
            {
                visit[i] = 1;//방문표시
                arr[k] = i; //i값을 arr에 저장
                dfs(k + 1); //더 깊게 들어가자(M까지)
                visit[i] = 0; //백트래킹 설정
            }
        }

    }

}

int main() {
    cin >> N >> M;
    dfs(0);
}
