#include <iostream>
#include <stack>
using namespace std;
int arr[1000001];
int nge[1000001];
stack<int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n-1; i>=0; i--) {//뒤에서부터 비교
		while (!s.empty() && s.top() <= arr[i]) {//큰 숫자만 스택에 넣음
			s.pop();
		}
		if (s.empty()) {
			nge[i] = -1;
		}
		else {
			nge[i] = s.top();
		}
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << nge[i] << " ";
	}
	return 0;
}