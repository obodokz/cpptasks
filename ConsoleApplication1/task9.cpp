#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Функция для поиска в ширину в графе
void bfs(vector<vector<int>>& adjList, int start) {
    int V = adjList.size();
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
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

    cout << "Результат обхода в ширину (BFS) начиная с вершины 0:" << endl;
    bfs(adjList, 0);
    cout << endl;

    return 0;
}