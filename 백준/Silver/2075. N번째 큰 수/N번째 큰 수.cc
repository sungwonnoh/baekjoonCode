#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    priority_queue<int, vector<int>, greater<int>> q;//최소 힙 선언
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (q.size() < n) {//n 이하일때만 삽입
                q.push(num);
            }
            else if (num > q.top()) {
                q.pop();
                q.push(num);
            }
        }
    }
    cout << q.top();
    return 0;
}
