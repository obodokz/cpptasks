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
    std::cout << "������� ���������� ������ � �����: ";
    std::cin >> n;
    std::cout << "������� ���������� ���� � �����: ";
    std::cin >> m;

    // ������������� ������� ��������� ������
    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n, 0));

    std::cout << "������� ���� � ������� '��� �������1 �������2', ��� ���: 1 - �����������������, 2 - ���������������" << std::endl;
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
            std::cerr << "�������� ��� �����" << std::endl;
            return 1;
        }
    }

    std::cout << "������� ���������:" << std::endl;
    print_adjacency_matrix(adjacencyMatrix);

    return 0;
}