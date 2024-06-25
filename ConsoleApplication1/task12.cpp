#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ������� ��� ������ � ������� (DFS)
void dfs(int u, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& component) {
    stack<int> st;
    st.push(u);
    visited[u] = true;

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        component.push_back(v); // ��������� ������� � ������� ���������� ���������

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
}

// ������� ��� ������ ��������� ��������� � �����
vector<vector<int>> findConnectedComponents(vector<vector<int>>& adjList, int V) {
    vector<vector<int>> components;
    vector<bool> visited(V, false);

    for (int u = 0; u < V; ++u) {
        if (!visited[u]) {
            vector<int> component;
            dfs(u, adjList, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

// ������ �������������
int main() {
    int V = 7; // ���������� ������

    // ������������� ������ ��������� ��� ������� �����
    vector<vector<int>> adjList(V);
    adjList[0] = { 1 };
    adjList[1] = { 0, 2 };
    adjList[2] = { 1 };
    adjList[3] = { 4 };
    adjList[4] = { 3 };
    adjList[5] = { 6 };
    adjList[6] = { 5 };

    // ����� ��������� ���������
    vector<vector<int>> components = findConnectedComponents(adjList, V);

    // ����� ��������� ���������
    cout << "���������� ��������� �����:" << endl;
    for (size_t i = 0; i < components.size(); ++i) {
        cout << "���������� " << i + 1 << ": ";
        for (int vertex : components[i]) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
