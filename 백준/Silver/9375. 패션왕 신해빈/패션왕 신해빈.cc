#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i< n; i++) {
		map <string, int> m;//map 사용
		int num;
		cin >> num;
		int result = 1;
		for (int j = 0; j < num; j++) {
			string name, kind;
			cin >> name >> kind;
			if (m.find(kind) == m.end()) {//해당값이 없으면 end
				//m.insert({ kind, 1 });
				m[kind] = 1;//종류와 개수저장
			}
			else {
				m[kind]++; //존재하면 값 증가
			}
		}

		for (auto k : m) {
			result *= k.second + 1;//종류 개수에 따라
		}
		cout << result - 1 << endl;//아무것도 안입은 경우 제외
	}
}
