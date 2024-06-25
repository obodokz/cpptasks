#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> adjacency_matrix_to_edge_list(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::pair<int, int>> edges;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] == 1) {
                edges.emplace_back(i + 1, j + 1); // +1 для вывода вершин в формате 1-based
            }
        }
    }
    return edges;
}

int main() {
    int n;
    std::cout << "Введите количество вершин в графе: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "Введите матрицу смежности:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::pair<int, int>> edge_list = adjacency_matrix_to_edge_list(matrix);

    std::cout << "Список рёбер:" << std::endl;
    for (const auto& edge : edge_list) {
        std::cout << "(" << edge.first << ", " << edge.second << ")" << std::endl;
    }

    return 0;
}