#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

bool compare(vector<pair<int, int>>& arr, int src, int dst, int k) {
    if (abs(arr[dst].first - arr[src].first) + abs(arr[dst].second - arr[src].second) <= k) return true;
    return false;
}

void clearQueues(queue<int>* q, queue<int>* rez) {
    delete(q);
    delete(rez);
}

int main() {

    //input data
    int n, k, src, dst;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cin >> k;
    cin >> src >> dst;
    src--;
    dst--;

    //solution
    if (src == dst || arr[src].first == arr[dst].first && arr[src].second == arr[dst].second) {
        cout << 0;
        return 0;
    }

    int count = 1;
    vector<int> mark(n);
    auto q = new queue<int>;
    auto rez = new queue<int>;
    mark[src] = 1;
    mark[dst] = 1;
    q->push(dst);

    while (!q->empty()) {
        dst = q->front();
        q->pop();

        if (compare(arr, src, dst, k)) {
            cout << count;
            clearQueues(q, rez);
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (mark[i] != 1 && compare(arr, i, dst, k)) {
                rez->push(i);
                mark[i] = 1;
            }
        }

        if (q->empty()) {
            delete(q);
            count++;
            q = rez;
            rez = new queue<int>;
        }
    }
    clearQueues(q, rez);
    cout << -1;
    return 0;
}