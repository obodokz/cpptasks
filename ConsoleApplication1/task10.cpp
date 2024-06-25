#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// Функция для обхода в глубину в графе
void dfs(vector<vector<int>>& adjList, int start) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    stack<int> st;

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

// Пример использования
int main() {
    int V = 6; // Количество вершин

    // Инициализация списка смежности для примера графа
    vector<vector<int>> adjList(V);
    adjList[0] = { 1, 2 };
    adjList[1] = { 0, 3, 4 };
    adjList[2] = { 0, 4 };
    adjList[3] = { 1, 5 };
    adjList[4] = { 1, 2, 5 };
    adjList[5] = { 3, 4 };

    cout << "Результат обхода в глубину (DFS) начиная с вершины 0:" << endl;
    dfs(adjList, 0);
    cout << endl;

    return 0;
}
