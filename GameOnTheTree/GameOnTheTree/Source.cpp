#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int dfs(int node, int count, int k, bool turn, bool reverse, unordered_map<int, vector<int>>& map, string& str) {
	if (map[node].empty()) {
		switch (str[node - 1]) {
		case '-':
			return (turn ^ reverse ? -1 : 1);
		case '+':
			return (turn ^ reverse ? 1 : -1);
		default:
			return 0;
		}
	}

	int res = 0;
	for (int i = 0; i < map[node].size(); i++) {
		int tmp = dfs(map[node][i], count + 1, k, !turn, reverse, map, str);

		if (i == 0 && (count != k || !reverse)) res = tmp;
		else res = (turn ? max(res, tmp) : min(res, tmp));

		if (count == k && i == map[node].size() - 1 && !reverse) {
			i = -1;
			reverse = true;
		}
	}
	return res;
}

int main() {
	int n, k;
	string str;
	unordered_map<int, vector<int>> map;

	cin >> n >> k;
	cin >> str;
	for (int i = 0; i < n - 1; i++) {
		int src, dst;
		cin >> src >> dst;
		map[src].push_back(dst);
	}

	switch (dfs(1, 0, k, true, false, map, str)) {
	case 1:
		cout << "First"; break;
	case -1:
		cout << "Second"; break;
	default:
		cout << "Draw"; break;
	}
}