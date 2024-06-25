//deikstra

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; // Пара (расстояние, вершина)

const int INF = numeric_limits<int>::max(); // Бесконечность для не достижимых вершин

// Функция для поиска кратчайших путей от начальной вершины с помощью алгоритма Дейкстры
vector<int> dijkstra(vector<vector<pii>>& adjList, int startVertex, int V) {
    vector<int> dist(V, INF); // Вектор для хранения минимальных расстояний
    dist[startVertex] = 0; // Расстояние до начальной вершины равно 0

    // Мин-куча для хранения пар (расстояние, вершина)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, startVertex }); // Добавляем начальную вершину в кучу

    while (!pq.empty()) {
        int u = pq.top().second; // Извлекаем вершину с минимальным расстоянием
        int currDist = pq.top().first;
        pq.pop();

        // Если текущее расстояние больше уже найденного минимального расстояния, пропускаем её
        if (currDist > dist[u]) continue;

        // Обходим смежные вершины
        for (auto& edge : adjList[u]) {
            int v = edge.second;
            int weight = edge.first;

            // Если найдено более короткое расстояние до вершины v через u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // Обновляем расстояние
                pq.push({ dist[v], v }); // Добавляем вершину в кучу
            }
        }
    }

    return dist;
}

// Пример использования
int main() {
    int V = 5; // Количество вершин

    // Инициализация списка смежности для примера графа
    vector<vector<pii>> adjList(V);
    // Пример графа с рёбрами и весами
    adjList[0].push_back({ 10, 1 });
    adjList[0].push_back({ 5, 2 });
    adjList[1].push_back({ 1, 3 });
    adjList[2].push_back({ 2, 1 });
    adjList[2].push_back({ 6, 3 });
    adjList[3].push_back({ 4, 4 });
    adjList[4].push_back({ 3, 0 });
    adjList[4].push_back({ 9, 2 });

    int startVertex = 0; // Начальная вершина

    // Вызов функции для поиска кратчайших путей от начальной вершины
    vector<int> shortestPaths = dijkstra(adjList, startVertex, V);

    // Вывод кратчайших путей
    cout << "Кратчайшие пути от вершины " << startVertex << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "До вершины " << i << ": " << shortestPaths[i] << "\n";
    }

    return 0;
}
