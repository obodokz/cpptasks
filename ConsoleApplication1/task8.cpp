#include <iostream>
#include <vector>

const int INF = 1e9;

// Функция для вывода матрицы смежности
void print_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для нахождения транзитивного замыкания графа
void floyd_warshall_transitive_closure(std::vector<std::vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    std::vector<std::vector<int>> closure = adjMatrix;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    std::cout << "Транзитивное замыкание матрицы смежности:" << std::endl;
    print_matrix(closure);
}

int main() {
    int n = 4; // Количество вершин в графе
    std::vector<std::vector<int>> adjMatrix = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 0}
    };

    std::cout << "Исходная матрица смежности:" << std::endl;
    print_matrix(adjMatrix);

    floyd_warshall_transitive_closure(adjMatrix);

    return 0;
}