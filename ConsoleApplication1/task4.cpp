#include <iostream>
#include <vector>

// Описание констант
const int N = 4; // Количество вершин в графе
const int M = 4; // Количество рёбер в графе

const std::pair<int, int> edges[M] = {
    {1, 2},
    {1, 4},
    {2, 3},
    {3, 4}
};

// Функция для вывода матрицы смежности
void print_adjacency_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Инициализация матрицы смежности нулями
    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N, 0));

    // Заполнение матрицы смежности на основе списка рёбер
    for (int i = 0; i < M; ++i) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1; // Поскольку граф неориентированный
    }

    // Вывод матрицы смежности
    std::cout << "Матрица смежности:" << std::endl;
    print_adjacency_matrix(adjacencyMatrix);

    return 0;
}