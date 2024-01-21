#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	int cnt = 0;
	stack<char> in;//스택 선언
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length();j++) {
			if (in.empty()) {
				in.push(s[j]);
			}
			else {
				if (in.top() == s[j]) {
					in.pop();
				}
				else {
					in.push(s[j]);
				}
			}
		}
		if (in.empty()) {
			cnt++;
		}
		while (!in.empty()) {
			in.pop();
		}
	}

	cout << cnt;
	return 0;
}
