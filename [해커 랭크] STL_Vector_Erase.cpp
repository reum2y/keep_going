//https://www.hackerrank.com/challenges/vector-erase/problem

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int a, b;
    //����� �ʱ�ȭ
    //���� : vector<int>::iterator iter; (���� �ݺ��� iter����)
    //�ʱ�ȭ :iter=v.begin(); (���� �ݺ��� iter�� v�� �������� ����Ŵ)
    vector<int>::iterator iter = v.begin();

    //Ư����ġ erase
    cin >> a;
    iter += (a - 1);
    v.erase(iter);

    //������ �޾Ƽ� ������ŭ erase
    //erase�� v.erase(a,b)��� ���� �� [a,b)�̴�. 
    //a�̻�, b�̸��� ����
    cin >> a >> b;
    iter = v.begin();
    v.erase(iter + a - 1, iter + b - 1);

    //�������
    cout << v.size() << endl;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " "; //*iter�� iter�� ����Ű�� ��
    }

    return 0;
}