//deikstra

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // ���� (����������, �������)

const int INF = numeric_limits<int>::max(); // ������������� ��� �� ���������� ������

// ������� ��� ������ ���������� ����� �� ��������� ������� � ������� ��������� ��������
vector<int> dijkstra(vector<vector<pii>>& adjList, int startVertex, int V) {
    vector<int> dist(V, INF); // ������ ��� �������� ����������� ����������
    dist[startVertex] = 0; // ���������� �� ��������� ������� ����� 0

    // ���-���� ��� �������� ��� (����������, �������)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, startVertex }); // ��������� ��������� ������� � ����

    while (!pq.empty()) {
        int u = pq.top().second; // ��������� ������� � ����������� �����������
        int currDist = pq.top().first;
        pq.pop();

        // ���� ������� ���������� ������ ��� ���������� ������������ ����������, ���������� �
        if (currDist > dist[u]) continue;

        // ������� ������� �������
        for (auto& edge : adjList[u]) {
            int v = edge.second;
            int weight = edge.first;

            // ���� ������� ����� �������� ���������� �� ������� v ����� u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // ��������� ����������
                pq.push({ dist[v], v }); // ��������� ������� � ����
            }
        }
    }

    return dist;
}

// ������ �������������
int main() {
    int V = 5; // ���������� ������

    // ������������� ������ ��������� ��� ������� �����
    vector<vector<pii>> adjList(V);
    // ������ ����� � ������ � ������
    adjList[0].push_back({ 10, 1 });
    adjList[0].push_back({ 5, 2 });
    adjList[1].push_back({ 1, 3 });
    adjList[2].push_back({ 2, 1 });
    adjList[2].push_back({ 6, 3 });
    adjList[3].push_back({ 4, 4 });
    adjList[4].push_back({ 3, 0 });
    adjList[4].push_back({ 9, 2 });

    int startVertex = 0; // ��������� �������

    // ����� ������� ��� ������ ���������� ����� �� ��������� �������
    vector<int> shortestPaths = dijkstra(adjList, startVertex, V);

    // ����� ���������� �����
    cout << "���������� ���� �� ������� " << startVertex << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "�� ������� " << i << ": " << shortestPaths[i] << "\n";
    }

    return 0;
}
