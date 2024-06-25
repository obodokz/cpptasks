#include <iostream>
#include <vector>

void print_adjacency_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cout << "Введите количество вершин в графе: ";
    std::cin >> n;
    std::cout << "Введите количество рёбер в графе: ";
    std::cin >> m;

    // Инициализация матрицы смежности нулями
    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n, 0));

    std::cout << "Введите рёбра в формате 'тип вершина1 вершина2', где тип: 1 - неориентированное, 2 - ориентированное" << std::endl;
    for (int i = 0; i < m; ++i) {
        int type, u, v;
        std::cin >> type >> u >> v;
        if (type == 1) {
            adjacencyMatrix[u - 1][v - 1] = 1;
            adjacencyMatrix[v - 1][u - 1] = 1;
        }
        else if (type == 2) {
            adjacencyMatrix[u - 1][v - 1] = 2;
        }
        else {
            std::cerr << "Неверный тип ребра" << std::endl;
            return 1;
        }
    }

    std::cout << "Матрица смежности:" << std::endl;
    print_adjacency_matrix(adjacencyMatrix);

    return 0;
}