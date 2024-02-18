#include <iostream>
#include <vector>
using namespace std;
int n, d;
int ans = 0;
int visit[50];
vector<int> tree[50];
void dfs(int x) {
	bool leaf = true;//리프노드인지
	for (int i = 0; i < tree[x].size(); i++) {
		if (tree[x][i] == d) {
			continue;
		}
		else {
			leaf = false;
			dfs(tree[x][i]);
		}
	}
	if (leaf) {
		ans++;
	}
}
int main() {
	int root = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;//첫번째노드
		}
		else {
			tree[parent].push_back(i);
		}
	}
	cin >> d;//지울 노드번호
	if (d == root) {
		cout << "0";
	}
	else {
		dfs(root);
		cout << ans;
	}
	
	return 0;
}