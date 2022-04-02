#include <iostream>
using namespace std;

int N, M;
int arr[9];
int visit[9] = { 0, };
//1���� n���� �ڿ��� �� m���� �ߺ����� ����
//dfs�� �̿��� ��Ʈ��ŷ
//dfs�� �����̳� ��͸� �̿� - ���� ��� ����

void dfs(int k) {//���� ��ġ
    if (k == M) {//��ǥ�� M���� �����ߴٸ�
        for (int i = 0; i < M; i++)
            cout << arr[i] << " " << "\n";
        //cout << "\n";
    }

    else {//��ǥ�� �������� �ʾҴٸ�
        for (int i = 1; i <= N; i++) {
            if (visit[i] != 1)//�湮 ���ߴٸ�
            {
                visit[i] = 1;//�湮ǥ��
                arr[k] = i; //i���� arr�� ����
                dfs(k + 1); //�� ��� ����(M����)
                visit[i] = 0; //��Ʈ��ŷ ����
            }
        }

    }

}

int main() {
    cin >> N >> M;
    dfs(0);
}