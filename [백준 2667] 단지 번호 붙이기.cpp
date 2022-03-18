#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 26
using namespace std;

int N, cnt; //����ũ��� ���� �� �� ũ�� ��Ͽ� cnt
string arr[MAX]; //�Է¿� ����
int visited[MAX][MAX];//�湮 ��Ͽ� �迭

int dx[4] = { 0,0,-1,1 }; //�����¿� x�����
int dy[4] = { 1,-1,0,0 }; //�����¿� y�����

vector<int> v;
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push({ x, y }); //ť�� ��ǥ ����
    visited[x][y] = 1; //�Է¹��� ��ǥ �湮
    cnt++;

    while (!q.empty()) { //��� ��ǥ�� Ž���� ������ �ݺ�
        //ť�� front��ǥ�� ������ǥ�� ����
        int a = q.front().first;
        int b = q.front().second;

        //ť�� front��ǥ ����
        q.pop();

        //���� ��ǥ�� �����¿�� ������ ��ǥ Ȯ��
        for (int i = 0; i < 4; i++) {
            int next_x = a + dx[i];
            int next_y = b + dy[i];
            //������ ��ǥ�� ���� ���� �����ϴ���, �湮���� �ִ���, ��������(�̵���������)
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N
                && visited[next_x][next_y] == 0 && arr[next_x][next_y] == '1') {
                q.push({ next_x, next_y });//������ǥ ť�� ����
                visited[next_x][next_y] = 1; //������ǥ �湮�Ѱ����� ����
                cnt++; //ī���� ++
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
            if (arr[i][j] == '1' && visited[i][j] == 0) { //������ 1(����)�̰� �湮���� ������
                cnt = 0;
                bfs(i, j);
                v.push_back(cnt);//���Ϳ� ������ ���ҵڿ� cnt�� ����
                //ó���� ��ǥ (0,0)���� �����Ѱ��� ������ ����(���� �� ��)�� �� 7��.(cnt=7)
                //�׷� ���� v�� 7��
                //�׸��� �ٽ� ������ ��ǥ�� ���ִ� ������ ã��
                //�� ���� ��ǥ���� ������ ������ �� 8��(cnt=8)
                //�ٵ� ������ cnt=7�̿����ϱ� �ٽ� 0���� �ٲ��� ���� bfs�Լ� ȣ���ؾߵ�
                //�ȱ׷��� �����Ǵϱ�!
                //�׷��� ��� �ݺ�...
            }
        }
    }

    sort(v.begin(), v.end()); //v�� ������������ ����

    cout << v.size() << endl; //v ������ (���� ��)
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

}