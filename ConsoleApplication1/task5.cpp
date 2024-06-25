#include <iostream>

// Описание констант
const int N = 4; // Количество вершин в графе
const int M = 4; // Количество рёбер в графе

const std::pair<int, int> edges[M] = {
    {1, 2},
    {1, 4},
    {2, 3},
    {3, 4}
};

// Функция для вывода предикатов инцидентности
void print_incidence_predicates(const std::pair<int, int> edges[], int numEdges) {
    for (int i = 0; i < numEdges; ++i) {
        std::cout << "I(" << edges[i].first << ", " << edges[i].second << ") = true" << std::endl;
        std::cout << "I(" << edges[i].second << ", " << edges[i].first << ") = true" << std::endl;
    }
}

int main() {
    std::cout << "Предикаты инцидентности:" << std::endl;
    print_incidence_predicates(edges, M);
    return 0;
}