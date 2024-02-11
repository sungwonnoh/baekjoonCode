#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool find(string s) {
	stack<char> p;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			p.push(s[i]);
		}
		else if (s[i] == ')') {
			if (p.empty() || p.top() != '(') {
				return false;
			}
			else {
				p.pop();
			}
		}
		else if (s[i] == ']') {
			if (p.empty() || p.top() != '[') {
				return false;
			}
			else {
				p.pop();
			}
		}
	}
	return p.empty();
}
int main() {
	string s;
	while (true) {
		getline(cin, s);
		if (s == ".") {
			break;
		}
		if (find(s)) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	return 0;
}