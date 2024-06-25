#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Функция для поиска эйлерова цикла в неориентированном графе
void findEulerianCycle(vector<vector<int>>& adjList, int V) {
    // Создание стека для хранения пути
    stack<int> circuit;
    // Создание вектора для хранения результирующего цикла
    vector<int> eulerianCycle;

    // Выбираем произвольную стартовую вершину
    int start = 0;

    circuit.push(start);

    while (!circuit.empty()) {
        int u = circuit.top();

        // Ищем следующую непосещённую вершину
        if (!adjList[u].empty()) {
            int v = adjList[u].back();
            adjList[u].pop_back(); // Удаляем ребро u-v из графа
            for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
                if (*it == u) {
                    adjList[v].erase(it); // Удаляем обратное ребро v-u
                    break;
                }
            }
            circuit.push(v); // Переходим к вершине v
        }
        else {
            eulerianCycle.push_back(u); // Добавляем вершину u в цикл
            circuit.pop(); // Извлекаем вершину из стека
        }
    }

    // Выводим результат
    reverse(eulerianCycle.begin(), eulerianCycle.end());
    cout << "Эйлеров цикл: ";
    for (int vertex : eulerianCycle) {
        cout << vertex << " ";
    }
    cout << endl;
}

// Пример использования
int main() {
    int V = 4; // Количество вершин

    // Инициализация списка смежности для неориентированного графа
    vector<vector<int>> adjList(V);
    adjList[0] = { 1, 2 };
    adjList[1] = { 0, 2 };
    adjList[2] = { 0, 1, 3 };
    adjList[3] = { 2 };

    findEulerianCycle(adjList, V);

    return 0;
}
