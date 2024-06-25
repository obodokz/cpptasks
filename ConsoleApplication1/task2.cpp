#include <iostream>
#include <vector>
#include <utility>

// Описание константной матрицы смежности смешанного графа
const int N = 4; // Количество вершин в графе
const int adjacencyMatrix[N][N] = {
    {0, 2, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 0, 2},
    {2, 0, 0, 0}
};

// Функция преобразования матрицы смежности в список рёбер
std::vector<std::pair<std::string, std::pair<int, int>>> adjacency_matrix_to_edge_list(const int matrix[N][N], int n) {
    std::vector<std::pair<std::string, std::pair<int, int>>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                edges.push_back({ "неориентированное", {i + 1, j + 1} });
            }
            else if (matrix[i][j] == 2) {
                edges.push_back({ "ориентированное", {i + 1, j + 1} });
            }
        }
    }
    return edges;
}

int main() {
    // Преобразование матрицы смежности в список рёбер
    std::vector<std::pair<std::string, std::pair<int, int>>> edge_list = adjacency_matrix_to_edge_list(adjacencyMatrix, N);

    // Вывод списка рёбер
    std::cout << "Список рёбер:" << std::endl;
    for (const auto& edge : edge_list) {
        std::cout << edge.first << " ребро: (" << edge.second.first << ", " << edge.second.second << ")" << std::endl;
    }

    return 0;
}