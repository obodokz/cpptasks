#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> pii; // ���� (��� �����, �������)

// ������� ��� ������ ������������ ������ ���������� �����
vector<pair<int, int>> primMST(vector<vector<pii>>& adjList, int V) {
    vector<pair<int, int>> mst; // ����� ������������ ������
    vector<bool> visited(V, false); // ������ ��� ������� ���������� ������

    // ���-���� ��� ������ ������������ �����
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // �������� � ������� 0 (����� �������� � ����� ������ �������)
    pq.push({ 0, 0 }); // (���, �������)

    while (!pq.empty()) {
        int u = pq.top().second; // �������� ������� � ����������� �����
        int weight = pq.top().first; // �������� ����������� ���
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        if (u != 0) { // ��������� ��������� �������, �.�. ��� �� ��� ����������� �����
            mst.push_back({ weight, u }); // ��������� ����� � ������������ ������
        }

        // ���������� ������� �������
        for (auto& edge : adjList[u]) {
            int v = edge.second;
            int w = edge.first;
            if (!visited[v]) {
                pq.push({ w, v });
            }
        }
    }

    return mst;
}

// ������ �������������
int main() {
    int V = 5; // ���������� ������

    // ������������� ������ ��������� ��� ������� �����
    vector<vector<pii>> adjList(V);
    // ������ ����� � ������ � ������
    adjList[0].push_back({ 1, 1 });
    adjList[0].push_back({ 2, 2 });
    adjList[1].push_back({ 1, 0 });
    adjList[1].push_back({ 3, 3 });
    adjList[1].push_back({ 4, 4 });
    adjList[2].push_back({ 2, 0 });
    adjList[2].push_back({ 3, 3 });
    adjList[3].push_back({ 3, 1 });
    adjList[3].push_back({ 3, 2 });
    adjList[3].push_back({ 4, 4 });
    adjList[4].push_back({ 4, 1 });
    adjList[4].push_back({ 4, 3 });

    // ����� ������� ��� ������ ������������ ������
    vector<pair<int, int>> mst = primMST(adjList, V);

    // ����� ���� ������������ ������
    cout << "и��� ������������ ������ (���, �������):" << endl;
    for (auto& edge : mst) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }

    return 0;
}
