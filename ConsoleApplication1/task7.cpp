#include <iostream>
#include <vector>
#include <algorithm>
//алгоритма Краскала
// Структура для представления рёбер
struct Edge {
    int src, dest, weight;
};

// Структура для представления графа
struct Graph {
    int V, E;
    std::vector<Edge> edges;
};

// Структура для представления подмножества для алгоритма Union-Find
struct Subset {
    int parent, rank;
};

// Найти корень элемента i
int find(std::vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Объединить два поддерева x и y
void Union(std::vector<Subset>& subsets, int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Функция для построения остова графа с использованием алгоритма Краскала
void KruskalMST(Graph& graph) {
    int V = graph.V;
    std::vector<Edge> result; // Хранит результат
    int e = 0; // Индекс для результата
    int i = 0; // Индекс для сортированных рёбер

    // Шаг 1: Отсортировать все рёбра в порядке возрастания веса
    std::sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
        });

    // Создать V подмножеств с одним элементом
    std::vector<Subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Количество рёбер в MST равно V-1
    while (e < V - 1 && i < graph.edges.size()) {
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // Если включение этого рёбра не создаёт цикл, включить его в результат
        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    // Вывести построенный MST
    std::cout << "Построенные рёбра MST:\n";
    for (const auto& edge : result)
        std::cout << edge.src << " -- " << edge.dest << " == " << edge.weight << std::endl;
}

int main() {
    // Пример использования
    int V = 4; // Количество вершин в графе
    int E = 5; // Количество рёбер в графе
    Graph graph = { V, E, {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    } };

    KruskalMST(graph);

    return 0;
}