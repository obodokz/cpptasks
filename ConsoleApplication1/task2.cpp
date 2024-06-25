#include <iostream>
#include <vector>
#include <utility>

// �������� ����������� ������� ��������� ���������� �����
const int N = 4; // ���������� ������ � �����
const int adjacencyMatrix[N][N] = {
    {0, 2, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 0, 2},
    {2, 0, 0, 0}
};

// ������� �������������� ������� ��������� � ������ ����
std::vector<std::pair<std::string, std::pair<int, int>>> adjacency_matrix_to_edge_list(const int matrix[N][N], int n) {
    std::vector<std::pair<std::string, std::pair<int, int>>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                edges.push_back({ "�����������������", {i + 1, j + 1} });
            }
            else if (matrix[i][j] == 2) {
                edges.push_back({ "���������������", {i + 1, j + 1} });
            }
        }
    }
    return edges;
}

int main() {
    // �������������� ������� ��������� � ������ ����
    std::vector<std::pair<std::string, std::pair<int, int>>> edge_list = adjacency_matrix_to_edge_list(adjacencyMatrix, N);

    // ����� ������ ����
    std::cout << "������ ����:" << std::endl;
    for (const auto& edge : edge_list) {
        std::cout << edge.first << " �����: (" << edge.second.first << ", " << edge.second.second << ")" << std::endl;
    }

    return 0;
}