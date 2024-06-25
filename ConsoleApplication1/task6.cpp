#include <iostream>
#include <vector>
#include <set>

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

// ���������� ������� ����� �������� ����
void create_subgraph_by_removing_edges(const std::vector<std::pair<int, int>>& edges, int n, const std::set<int>& edges_to_remove) {
    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < edges.size(); ++i) {
        if (edges_to_remove.find(i) == edges_to_remove.end()) {
            int u = edges[i].first - 1;
            int v = edges[i].second - 1;
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1;
        }
    }
    std::cout << "������� ��������� �������:" << std::endl;
    print_adjacency_matrix(adjacencyMatrix);
}

// ���������� �������� ����� �������� ������
void create_subgraph_by_removing_vertices(const std::vector<std::pair<int, int>>& edges, int n, const std::set<int>& vertices_to_remove) {
    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n, 0));
    for (const auto& edge : edges) {
        int u = edge.first - 1;
        int v = edge.second - 1;
        if (vertices_to_remove.find(u) == vertices_to_remove.end() && vertices_to_remove.find(v) == vertices_to_remove.end()) {
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1;
        }
    }
    std::cout << "������� ��������� ��������:" << std::endl;
    print_adjacency_matrix(adjacencyMatrix);
}

int main() {
    // �������� ��� ���� ��� �������
    std::set<int> edges_to_remove = { 0, 1, 2 }; // ������� ����, ������� ����� �������
    create_subgraph_by_removing_edges(std::vector<std::pair<int, int>>(edges, edges + M), N, edges_to_remove);

    // �������� ��� ������ ��� ��������
    std::set<int> vertices_to_remove = { 0, 1, 2 }; // ������� ������, ������� ����� �������
    create_subgraph_by_removing_vertices(std::vector<std::pair<int, int>>(edges, edges + M), N, vertices_to_remove);

    return 0;
}
