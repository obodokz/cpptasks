#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> pii; // Пара (вес ребра, вершина)

// Функция для поиска минимального остова алгоритмом Прима
vector<pair<int, int>> primMST(vector<vector<pii>>& adjList, int V) {
    vector<pair<int, int>> mst; // Ребра минимального остова
    vector<bool> visited(V, false); // Массив для отметки посещённых вершин

    // Мин-куча для выбора минимального ребра
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Начинаем с вершины 0 (можно начинать с любой другой вершины)
    pq.push({ 0, 0 }); // (вес, вершина)

    while (!pq.empty()) {
        int u = pq.top().second; // Получаем вершину с минимальным весом
        int weight = pq.top().first; // Получаем минимальный вес
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        if (u != 0) { // Исключаем начальную вершину, т.к. для неё нет предыдущего ребра
            mst.push_back({ weight, u }); // Добавляем ребро к минимальному остову
        }

        // Перебираем смежные вершины
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

// Пример использования
int main() {
    int V = 5; // Количество вершин

    // Инициализация списка смежности для примера графа
    vector<vector<pii>> adjList(V);
    // Пример графа с рёбрами и весами
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

    // Вызов функции для поиска минимального остова
    vector<pair<int, int>> mst = primMST(adjList, V);

    // Вывод рёбер минимального остова
    cout << "Рёбра минимального остова (вес, вершина):" << endl;
    for (auto& edge : mst) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }

    return 0;
}
