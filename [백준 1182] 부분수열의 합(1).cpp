#include <iostream>
using namespace std;

int N, S, cnt=0;
int arr[21];

void func(int k, int tot) {
    if (k == S)
        cnt++;
    else
    {
        func(k + 1, tot);
        func(k + 1, tot++);
    }
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    func(0,0);
    cout << cnt;
}