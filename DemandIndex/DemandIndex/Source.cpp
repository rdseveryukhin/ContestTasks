#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> tab;
struct comp {
	bool operator()(const int& x, const int& y) const {
		return tab[x].size() > tab[y].size();
	}
};

int main() {
	int n, s;

	cin >> n >> s;
	vector<pair<double, double>> points(n);
	vector<int> indexes(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points[i].first = (x == 0 ? 1 : x);
		points[i].second = (y == 0 ? 1 : y);
		indexes[i] = i;
	}

	sort(indexes.begin(), indexes.end(),
		[&](const int& x, const int& y) {
			double sx = points[x].first * points[x].second;
			double sy = points[y].first * points[y].second;
			if ((sx <= s) ^ (sy <= s)) return sx <= s;
			else return sx > sy;
		});

	map <int, pair<double, double>, comp> map;
	int num = 1;

	if (n > 0) {
		map[0] = points[indexes[0]];
		tab[0].push_back(indexes[0] + 1);
	}

	for (int i = 1; i < n; i++) {
		auto pair = points[indexes[i]];
		if (pair.first * pair.second > s) break;
		bool flag = false;

		for (auto it = map.begin(); it != map.end(); it++) {
			if (pair.first <= it->second.first && pair.second <= it->second.second) {
				tab[it->first].push_back(indexes[i] + 1);
				flag = true;
			}
		}
		if (!flag) {
			map[num] = pair;
			tab[num].push_back(indexes[i] + 1);
			num++;
		}
	}

	auto res = map.begin();
	cout << tab[res->first].size() << endl;
	for (auto val : tab[res->first]) {
		cout << val << ' ';
	}
}