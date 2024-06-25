#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ������� ��� ������ �������� ����� � ����������������� �����
void findEulerianCycle(vector<vector<int>>& adjList, int V) {
    // �������� ����� ��� �������� ����
    stack<int> circuit;
    // �������� ������� ��� �������� ��������������� �����
    vector<int> eulerianCycle;

    // �������� ������������ ��������� �������
    int start = 0;

    circuit.push(start);

    while (!circuit.empty()) {
        int u = circuit.top();

        // ���� ��������� ������������ �������
        if (!adjList[u].empty()) {
            int v = adjList[u].back();
            adjList[u].pop_back(); // ������� ����� u-v �� �����
            for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
                if (*it == u) {
                    adjList[v].erase(it); // ������� �������� ����� v-u
                    break;
                }
            }
            circuit.push(v); // ��������� � ������� v
        }
        else {
            eulerianCycle.push_back(u); // ��������� ������� u � ����
            circuit.pop(); // ��������� ������� �� �����
        }
    }

    // ������� ���������
    reverse(eulerianCycle.begin(), eulerianCycle.end());
    cout << "������� ����: ";
    for (int vertex : eulerianCycle) {
        cout << vertex << " ";
    }
    cout << endl;
}

// ������ �������������
int main() {
    int V = 4; // ���������� ������

    // ������������� ������ ��������� ��� ������������������ �����
    vector<vector<int>> adjList(V);
    adjList[0] = { 1, 2 };
    adjList[1] = { 0, 2 };
    adjList[2] = { 0, 1, 3 };
    adjList[3] = { 2 };

    findEulerianCycle(adjList, V);

    return 0;
}
