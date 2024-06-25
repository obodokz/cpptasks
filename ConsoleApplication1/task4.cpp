#include <iostream>
#include <vector>

// �������� ��������
const int N = 4; // ���������� ������ � �����
const int M = 4; // ���������� ���� � �����

const std::pair<int, int> edges[M] = {
    {1, 2},
    {1, 4},
    {2, 3},
    {3, 4}
};

// ������� ��� ������ ������� ���������
void print_adjacency_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // ������������� ������� ��������� ������
    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N, 0));

    // ���������� ������� ��������� �� ������ ������ ����
    for (int i = 0; i < M; ++i) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1; // ��������� ���� �����������������
    }

    // ����� ������� ���������
    std::cout << "������� ���������:" << std::endl;
    print_adjacency_matrix(adjacencyMatrix);

    return 0;
}