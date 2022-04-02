#include<iostream>
using namespace std;
int N;
int col[15];
int cnt=0;

bool check(int m) {
    for (int i = 0; i < m; i++) {
        //�밢���̰ų� ���� ����
        if (col[i] == col[m] || abs(col[i]-col[m])==abs(i-m))
            return false;
        //col[i] = x��ǥ
        //i = y��ǥ
    }
    return true;
}

void dfs(int k) {
    //��Ʈ��ŷ, dfs-���
    if (k == N) {
        cnt++;
    }
    else {
        for (int i = 0; i < N; i++) {
            col[k] = i;// �ش� ��ġ�� ���� ��ġ
            if (check(k) == true) {// ��ȿ�ϴٸ� �������� �� ��ġ, 
                //��ȿ�����ʴٸ� �ٸ� ��ġ�� �� ��ġ ����
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
