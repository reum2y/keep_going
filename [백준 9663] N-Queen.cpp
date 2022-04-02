#include<iostream>
using namespace std;
int N;
int col[15];
int cnt=0;

bool check(int m) {
    for (int i = 0; i < m; i++) {
        //대각선이거나 같은 라인
        if (col[i] == col[m] || abs(col[i]-col[m])==abs(i-m))
            return false;
        //col[i] = x좌표
        //i = y좌표
    }
    return true;
}

void dfs(int k) {
    //백트래킹, dfs-재귀
    if (k == N) {
        cnt++;
    }
    else {
        for (int i = 0; i < N; i++) {
            col[k] = i;// 해당 위치에 퀸을 배치
            if (check(k) == true) {// 유효하다면 다음행의 퀸 배치, 
                //유효하지않다면 다른 위치로 퀸 배치 변경
                dfs(k + 1);
            }


        }
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << cnt;

}
