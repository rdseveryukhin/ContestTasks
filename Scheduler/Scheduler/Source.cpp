#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Task {
	int id = 0;
	int createTime = 0;
	int numQueue = 0;
	int processTime = 0;
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<queue<Task>> queues(k);
	vector<int> workers(m);
	vector<pair<int, int>> res(n);

	for (int i = 0; i < n; i++) {
		Task tmp;
		tmp.id = i;
		cin >> tmp.createTime >> tmp.numQueue >> tmp.processTime;
		queues[tmp.numQueue - 1].push(tmp);
	}

	while (!queues.empty()) {
		for (int i = 0; i < queues.size(); i++) {
			if (queues[i].empty()) {
				queues.erase(queues.begin() + i);
				i--;
				continue;
			}

			int create = queues[i].front().createTime;
			int worker = 0;
			int time = workers[worker];
			for (int i = 0; i < workers.size(); i++) {
				if (workers[i] <= create) {
					worker = i;
					break;
				}
				if (workers[i] < time) {
					worker = i;
					time = workers[i];
				}
			}

			int process = queues[i].front().processTime;
			if (workers[worker] < create) {
				workers[worker] = create + process;
			}
			else {
				workers[worker] += process;
				create = time;
			}

			res[queues[i].front().id] = make_pair(worker + 1, create);
			queues[i].pop();
		}
	}

	for (auto pair : res) {
		cout << pair.first << ' ' << pair.second << endl;
	}
}