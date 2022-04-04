#include <iostream>
using namespace std;

int N, S;
int arr[21];
int cnt = 0;


void func(int k, int total) {
    if (k == N) {
        if (total == S)
            cnt++;
        return;
    }
    func(k + 1, total);
    func(k + 1, total + arr[k]);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    func(0, 0);
    if (S == 0)
        cnt--;
    cout << cnt;
}