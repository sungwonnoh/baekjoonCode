#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string ps;
		cin >> ps;
		stack<char> s;
		bool isPs = true;
		for (int j = 0; j < ps.length(); j++) {
			if (ps[j]=='(') {
				s.push(ps[j]);
			}
			else {//')'일때
				if (s.empty() || s.top() != '(') {
					isPs = false;
					break;
				}
				else {// ( 와 )가 만나면 없어짐
					s.pop();
				}
			}
		}
		if (isPs && s.empty()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";

		}
	}
	return 0;
}