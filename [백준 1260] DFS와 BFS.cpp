#include<iostream> 
#include<queue>
using namespace std;

#define MAX_VALUE 1001//N�� 1~1000 �̹Ƿ� 1000��° �ε����� ���� -> ũ�� 1001���� 
int N, M, V; //��������, ��������, Ž������ ���� ��ȣ
int mat[MAX_VALUE][MAX_VALUE];
int visit[MAX_VALUE];

void dfs(int v);
void bfs(int v);

int main() {
    int x, y;//������ ����
    cin >> N >> M >> V; //N�� ��尳��, M�� �����ǰ���, V�� ó�� ��ġ�� ������ �Ǵ� ���
    for (int i = 0; i < M; i++) { //������ ������ŭ ���� �̾��� x�� y��带 �Է¹���
        cin >> x >> y;
        mat[x][y] = mat[y][x] = 1; //������� ǥ��
    }

    dfs(V);
    cout << endl;
    bfs(V);

    return 0;
}
void dfs(int v) {
    cout << v << " ";
    visit[v] = 1; //�湮�� ��� �迭�� 0->1
    for (int i = 1; i <= N; i++) { //����ȣ�� �����ϱ� ������ i=1���� ����
        if (visit[i] == 1 || mat[v][i] == 0)
            continue;
        dfs(i); //���� �̹� �湮�� ��忴�ų�, ������ ��尡 ���ٸ� ���


        // �ݺ��� �ȿ��� i++�� �ϱ����ؼ� ���� �Ȱ�����̰ų�, �����ؾ��� �������� ��������
        // ���� �湮���� ���� ����̰ų�, ������ ��常 �Ű澲�ڴ�. ������ ����
        // ��, if�� �������� �������(= ���� �湮���� ���� ����̰ų�, ������ ���) continue���� ���� �ݺ��� �� ���� ������ �´��� �ٽ� �ݺ��� ���� 
    }

}

void bfs(int v) {
    //����Ʈ�� �Ἥ pop(0)�ϰ� �Ǹ� �ð����⵵�� O(N)�̴�. 
    //�׷��� �ð����⵵�� O(1)�� queue ���

    queue<int> q; //bfs������ q ���
    q.push(v);
    visit[v] = 0; //�湮�� ��带 1->0

    while (!q.empty()) { //q�� ����� 0���� �ƴ����� Ȯ��
        v = q.front(); //q�� ���� ���� �� ���Ҹ� ����
        cout << v << ' ';
        q.pop();//q�� ���� ���� �� ���Ҹ� ����
        for (int i = 1; i <= N; i++) {
            if (visit[i] == 0 || mat[v][i] == 0)
                continue;
            q.push(i);//q�� ��(��)�� value�� �߰�
            visit[i] = 0;

        }
    }
}