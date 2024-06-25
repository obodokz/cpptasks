#include <iostream>
#include <vector>
#include <algorithm>
//��������� ��������
// ��������� ��� ������������� ����
struct Edge {
    int src, dest, weight;
};

// ��������� ��� ������������� �����
struct Graph {
    int V, E;
    std::vector<Edge> edges;
};

// ��������� ��� ������������� ������������ ��� ��������� Union-Find
struct Subset {
    int parent, rank;
};

// ����� ������ �������� i
int find(std::vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// ���������� ��� ��������� x � y
void Union(std::vector<Subset>& subsets, int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// ������� ��� ���������� ������ ����� � �������������� ��������� ��������
void KruskalMST(Graph& graph) {
    int V = graph.V;
    std::vector<Edge> result; // ������ ���������
    int e = 0; // ������ ��� ����������
    int i = 0; // ������ ��� ������������� ����

    // ��� 1: ������������� ��� ���� � ������� ����������� ����
    std::sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
        });

    // ������� V ����������� � ����� ���������
    std::vector<Subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // ���������� ���� � MST ����� V-1
    while (e < V - 1 && i < graph.edges.size()) {
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // ���� ��������� ����� ���� �� ������ ����, �������� ��� � ���������
        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    // ������� ����������� MST
    std::cout << "����������� ���� MST:\n";
    for (const auto& edge : result)
        std::cout << edge.src << " -- " << edge.dest << " == " << edge.weight << std::endl;
}

int main() {
    // ������ �������������
    int V = 4; // ���������� ������ � �����
    int E = 5; // ���������� ���� � �����
    Graph graph = { V, E, {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    } };

    KruskalMST(graph);

    return 0;
}