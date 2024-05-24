#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;//우선순위 큐 사용
int main() {
	int n, m;
	int sum = 0;
	int result = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		q.push(input);
		sum += input;
		while (sum >= m) {
			result++;
			sum -= q.top() * 2;//불만도가 가장 높은 순으로 제거
			q.pop();
		}
	}
	cout << result;
	return 0;
}