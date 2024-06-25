#include <iostream>

// �������� ��������
const int N = 4; // ���������� ������ � �����
const int M = 4; // ���������� ���� � �����

const std::pair<int, int> edges[M] = {
    {1, 2},
    {1, 4},
    {2, 3},
    {3, 4}
};

// ������� ��� ������ ���������� �������������
void print_incidence_predicates(const std::pair<int, int> edges[], int numEdges) {
    for (int i = 0; i < numEdges; ++i) {
        std::cout << "I(" << edges[i].first << ", " << edges[i].second << ") = true" << std::endl;
        std::cout << "I(" << edges[i].second << ", " << edges[i].first << ") = true" << std::endl;
    }
}

int main() {
    std::cout << "��������� �������������:" << std::endl;
    print_incidence_predicates(edges, M);
    return 0;
}