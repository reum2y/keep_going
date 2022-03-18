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
    //선언과 초기화
    //선언 : vector<int>::iterator iter; (벡터 반복자 iter선언)
    //초기화 :iter=v.begin(); (벡터 반복자 iter는 v의 시작점을 가리킴)
    vector<int>::iterator iter = v.begin();

    //특정위치 erase
    cin >> a;
    iter += (a - 1);
    v.erase(iter);

    //범위를 받아서 범위만큼 erase
    //erase는 v.erase(a,b)라고 했을 때 [a,b)이다. 
    //a이상, b미만의 범위
    cin >> a >> b;
    iter = v.begin();
    v.erase(iter + a - 1, iter + b - 1);

    //출력형태
    cout << v.size() << endl;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " "; //*iter는 iter가 가리키는 값
    }

    return 0;
}