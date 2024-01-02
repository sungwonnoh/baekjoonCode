#include <iostream>
using namespace std;

int main() {
	int n[9];
	int sum = 0, cnt = 0;
	int falsedwarf;//가짜들의 합
	int temp,one,two;
	for (int i = 0; i < 9; i++) {
		cin >> n[i];//난쟁이 9명 입력
		sum += n[i];
	}
	falsedwarf = sum - 100;//가짜 키의 합

	for (int i = 0; i < 9; i++) {//오름차순 정렬
		for (int j = 0; j < 9; j++) {
			if (n[i] < n[j]) {
				temp = n[i];
				n[i] = n[j];
				n[j] = temp;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (n[i] + n[j] == falsedwarf) {
				one = i;
				two = j;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == one || i == two) {
			continue;
		}
		else {
			cout << n[i] << endl;
		}
	}
	return 0;
}